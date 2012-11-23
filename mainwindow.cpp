#include <QtGui>
#include <QPushButton>
#include <QtWebKit>
#include <QWebView>
#include <QApplication>
#include <QKeySequence>

#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    source = new SourceWindow(this);
    setCentralWidget(source);

    createMenus();
    
    createStatusBar();
    createDockWindows();

    setWindowTitle(tr("ebe"));

    setUnifiedTitleAndToolBarOnMac(true);

    QFont *font = new QFont ( "courier" );
    qApp->setFont(*font);
    fontSize = 15;
    increaseFont();
}

void MainWindow::increaseFont()
{
    char style[40];

    fontSize++;
    sprintf(style,"* {font-size: %dpx}",fontSize);
    qApp->setStyleSheet(style);
    QFont f("courier");
    f.setPixelSize(fontSize);
    QFontMetrics fm(f);
    source->setLineNumberWidth(fm.width("x")*4+12);
}

void MainWindow::decreaseFont()
{
    char style[40];

    fontSize--;
    sprintf(style,"* {font-size: %dpx}",fontSize);
    qApp->setStyleSheet(style);
    QFont f("courier");
    f.setPixelSize(fontSize);
    QFontMetrics fm(f);
    source->setLineNumberWidth(fm.width("x")*4+12);
}

void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(tr("New"), source, SLOT(newFile()), QKeySequence::New );
    templateMenu = fileMenu->addMenu(tr("&Template"));
        templateMenu->addAction(tr("C Program"), source, SLOT(templateC()));
        templateMenu->addAction(tr("C++ Program"), source, SLOT(templateCpp()));
        templateMenu->addAction(tr("Assembly Program"), source,
                      SLOT(templateAssembly()));
        templateMenu->addAction(tr("Fortran Program"), source, SLOT(templateFortran()));
    fileMenu->addAction(tr("Open"), source, SLOT(open()), QKeySequence::Open );
    fileMenu->addAction(tr("Save"), source, SLOT(save()), QKeySequence::Save );
    fileMenu->addAction(tr("Save as"), source, SLOT(saveAs()) );
    fileMenu->addSeparator();
    fileMenu->addAction(tr("New project"), source, SLOT(newProject()) );
    fileMenu->addAction(tr("Open project"), source, SLOT(openProject()) );
    fileMenu->addAction(tr("Close project"), source, SLOT(closeProject()) );
    fileMenu->addSeparator();
    fileMenu->addAction(tr("Save settings"), source, SLOT(saveSettingsAs()) );
    fileMenu->addAction(tr("Save settings as"), source, SLOT(saveSettingsAs()) );
    fileMenu->addSeparator();
    fileMenu->addAction(tr("Quit"), qApp, SLOT(quit()), QKeySequence::Quit );

    editMenu = menuBar()->addMenu(tr("&Edit"));
    editMenu->addAction(tr("Cut"), source, SLOT(cut()), QKeySequence::Cut );
    editMenu->addAction(tr("Copy"), source, SLOT(copy()), QKeySequence::Copy );
    editMenu->addAction(tr("Paste"), source, SLOT(paste()), QKeySequence::Paste );
    editMenu->addSeparator();
    editMenu->addAction(tr("Undo"), source, SLOT(undo()), QKeySequence::Undo );
    editMenu->addAction(tr("Redo"), source, SLOT(redo()), QKeySequence::Redo );
    editMenu->addSeparator();
    editMenu->addAction(tr("Comment"), source, SLOT(Comment()),
                        QKeySequence("Ctrl+K") );
    editMenu->addAction(tr("Uncomment"), source, SLOT(unComment()),
                        QKeySequence("Ctrl+U")  );
    editMenu->addAction(tr("indent"), source, SLOT(indent()),
                        QKeySequence("Ctrl+>")  );
    editMenu->addAction(tr("Unindent"), source, SLOT(unIndent()),
                        QKeySequence("Ctrl+<")  );
    editMenu->addSeparator();
    editMenu->addAction(tr("Find"), source, SLOT(find()), QKeySequence::Find );
    editMenu->addSeparator();
    editMenu->addAction(tr("Select all"), source, SLOT(selectAll()),
                        QKeySequence::SelectAll );
    editMenu->addAction(tr("Select none"), source, SLOT(selectNone()),
                        QKeySequence("Ctrl+0") );
    editMenu->addSeparator();
    editMenu->addAction(tr("Prettify"), source, SLOT(Prettify()) );

    moveMenu = menuBar()->addMenu(tr("&Move"));
    moveMenu->addAction(tr("Page forward"), source, SLOT(pageForward()),
                        QKeySequence::MoveToNextPage );
    moveMenu->addAction(tr("Page backward"), source, SLOT(pageBackward()),
                        QKeySequence::MoveToPreviousPage );
    moveMenu->addAction(tr("Go to line 1"), source, SLOT(gotoFirstLine()),
                        QKeySequence::MoveToStartOfDocument );
    moveMenu->addAction(tr("Go to last line"), source, SLOT(gotoLastLine()),
                        QKeySequence::MoveToEndOfDocument );
    moveMenu->addAction(tr("Go to line n"), source, SLOT(gotoLine()),
                        QKeySequence("Ctrl+L") );
    moveMenu->addAction(tr("Go to top of screen"), source, SLOT(gotoTop()),
                        QKeySequence("Ctrl+T") );
    moveMenu->addAction(tr("Go to bottom"), source, SLOT(gotoBottom()),
                        QKeySequence("Ctrl+B") );
    moveMenu->addAction(tr("Move line to middle"), source, SLOT(cut()),
                        QKeySequence("Ctrl+M") );

    viewMenu = menuBar()->addMenu(tr("&View"));
    addToggle ( viewMenu, "Data window", this, SLOT(setDataDockVisible(bool)) );
    addToggle ( viewMenu, "Register window", this, SLOT(setRegisterDockVisible(bool)) );
    addToggle ( viewMenu, "Float register window", this, SLOT(setFloatDockVisible(bool)) );
    addToggle ( viewMenu, "Console window", this, SLOT(setConsoleDockVisible(bool)) );
    addToggle ( viewMenu, "Terminal window", this, SLOT(setTerminalDockVisible(bool)) );
    addToggle ( viewMenu, "Project window", this, SLOT(setProjectDockVisible(bool)) );
    addToggle ( viewMenu, "Tooltips", this, SLOT(setTooltipsVisible(bool)) );
    addToggle ( viewMenu, "Command line", source, SLOT(setCommandLineVisible(bool)) );

    fontMenu = menuBar()->addMenu(tr("F&ont"));
    fontMenu->addAction(tr("Increase font"), this, SLOT(increaseFont()),
                        QKeySequence::ZoomIn );
    fontMenu->addAction(tr("Decrease font"), this, SLOT(decreaseFont()),
                        QKeySequence::ZoomOut );

    helpMenu = menuBar()->addMenu(tr("&Help "));
    helpAction ( helpMenu, "Getting started", "start.html" );
    helpAction ( helpMenu, "Projects", "projects.html" );
    helpAction ( helpMenu, "Editing", "editing.html" );
    helpAction ( helpMenu, "Breakpoints", "breakpoints.html" );
    helpAction ( helpMenu, "Running", "running.html" );
    helpAction ( helpMenu, "About", "about.html" );

}

void MainWindow::setDataDockVisible(bool visible)
{
    dataDock->setVisible(visible);
}


void MainWindow::setRegisterDockVisible(bool visible)
{
    registerDock->setVisible(visible);
}


void MainWindow::setFloatDockVisible(bool visible)
{
    floatDock->setVisible(visible);
}


void MainWindow::setConsoleDockVisible(bool visible)
{
    consoleDock->setVisible(visible);
}


void MainWindow::setTerminalDockVisible(bool visible)
{
    terminalDock->setVisible(visible);
}


void MainWindow::setProjectDockVisible(bool visible)
{
    projectDock->setVisible(visible);
}

void MainWindow::addToggle ( QMenu *menu, QString text, QObject *object, const char *slot )
{
    QAction *action = new QAction ( text, this );
    action->setCheckable(true);
    action->setChecked(true);
    menu->addAction(action);
    connect ( action, SIGNAL(triggered(bool)), object, slot );
}


void MainWindow::helpAction ( QMenu *menu, QString text, QString file )
{
    QAction *action = new QAction( text, this );
    action->setData(file);
    menu->addAction(action);
    connect(action,SIGNAL(triggered()),this,SLOT(displayHelp()));
}

void MainWindow::displayHelp()
{
    QAction *action = (QAction *)sender();
    QWebView *view = new QWebView();
    view->load(QUrl("qrc:/html/"+action->data().toString()));
    view->show();
}

void MainWindow::quit()
{
    qDebug() << "Calling static QApp quit()";

    // FIXME: save project/files etc., before quitting
    QApplication::quit();
}

void MainWindow::createStatusBar()
{
    statusBar()->showMessage(tr("Ready"));
}

void MainWindow::createDockWindows()
{
    dataDock = new QDockWidget(tr("Data"), this);
    dataDock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::BottomDockWidgetArea);
    QPushButton *button = new QPushButton(tr("hello"),dataDock);
    button->setMinimumHeight(0);
    button->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Ignored);
    dataDock->setWidget(button);
    addDockWidget(Qt::LeftDockWidgetArea, dataDock);

    registerDock = new QDockWidget(tr("Registers"), this);
    registerDock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::BottomDockWidgetArea);
    registerWindow = new RegisterWindow(this);    
    registerDock->setWidget(registerWindow);
    addDockWidget(Qt::LeftDockWidgetArea, registerDock);

    floatDock = new QDockWidget(tr("Floating Point Registers"), this);
    floatDock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::BottomDockWidgetArea);
    button = new QPushButton(tr("hello"),floatDock);
    button->setMinimumHeight(0);
    button->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Ignored);
    floatDock->setWidget(button);
    addDockWidget(Qt::LeftDockWidgetArea, floatDock);

    projectDock = new QDockWidget(tr("Project"), this);
    projectDock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::BottomDockWidgetArea);
    button = new QPushButton(tr("hello"),projectDock);
    button->setMinimumHeight(0);
    button->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Ignored);
    projectDock->setWidget(button);
    addDockWidget(Qt::LeftDockWidgetArea, projectDock);

    terminalDock = new QDockWidget(tr("Terminal"), this);
    terminalDock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::BottomDockWidgetArea);
    terminal = new TerminalWindow(terminalDock);
    terminal->setMinimumHeight(20);
    terminal->setMinimumWidth(20);
    terminal->resize(300,100);
    terminal->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
    terminalDock->setWidget(terminal);
    addDockWidget(Qt::BottomDockWidgetArea, terminalDock);

    consoleDock = new QDockWidget(tr("Console"), this);
    consoleDock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::BottomDockWidgetArea);
    button = new QPushButton(tr("hello"),consoleDock);
    button->setMinimumHeight(0);
    button->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Ignored);
    consoleDock->setWidget(button);
    addDockWidget(Qt::BottomDockWidgetArea, consoleDock);

}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    printf("key %x\n",event->key());
    if ( event->matches(QKeySequence::ZoomIn) ) {
        increaseFont();
    } else if ( event->matches(QKeySequence::ZoomOut) ) {
        decreaseFont();
    }
    event->ignore();
}
