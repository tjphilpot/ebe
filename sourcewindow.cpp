#include "sourcewindow.h"
#include "sourceedit.h"
#include "commandline.h"
#include <QPushButton>
#include <QPlainTextEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTextCursor>
#include <QApplication>
#include <QKeyEvent>
#include <QFile>


SourceWindow::SourceWindow(QWidget *parent) : QFrame(parent)
{
    setFrameStyle ( QFrame::Box | QFrame::Raised );
    setLineWidth(3);
    setMidLineWidth(1);

    createLineNumberEdit();
    createTextEdit();

    QVBoxLayout *sourceLayout = new QVBoxLayout;
    sourceLayout->setSpacing(2);
    sourceLayout->setContentsMargins(10,10,10,10);
    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->setSpacing(6);
    buttonLayout->setContentsMargins(2,2,2,2);

    quitButton     = new QPushButton ( "Quit" );
    runButton      = new QPushButton ( "Run" );
    nextButton     = new QPushButton ( "Next" );
    stepButton     = new QPushButton ( "Step" );
    continueButton = new QPushButton ( "Continue" );
    stopButton     = new QPushButton ( "Stop" );
    buttonLayout->addWidget ( quitButton );
    buttonLayout->addWidget ( runButton );
    buttonLayout->addWidget ( nextButton );
    buttonLayout->addWidget ( stepButton );
    buttonLayout->addWidget ( continueButton );
    buttonLayout->addWidget ( stopButton );

    connect ( quitButton, SIGNAL(clicked()), parent, SLOT(quit()) );

    commandLine = new CommandLine();

    QHBoxLayout *editorLayout = new QHBoxLayout;
    editorLayout->setSpacing(2);
    editorLayout->setContentsMargins(3,3,3,3);

    editorLayout->addWidget(lineNumberEdit,0);
    editorLayout->addWidget(textEdit,1);

    sourceLayout->addLayout(buttonLayout);
    sourceLayout->addWidget(commandLine);
    sourceLayout->addLayout(editorLayout);
    setLayout(sourceLayout);
}

void SourceWindow::createLineNumberEdit()
{
    lineNumberEdit = new QPlainTextEdit(this);
    lineNumberEdit->setFixedWidth(60);
    lineNumberEdit->appendPlainText(QString("1234"));
    lineNumberEdit->setReadOnly(true);
}

void SourceWindow::setLineNumberWidth ( int width )
{
    lineNumberEdit->setFixedWidth(width);
}

void SourceWindow::setCommandLineVisible(bool visible)
{
    commandLine->setVisible(visible);
}

void SourceWindow::createTextEdit()
{
    textEdit = new SourceEdit(this);
    textEdit->appendPlainText("Text");
}

void SourceWindow::createButtons()
{
}

void SourceWindow::createCommandLineEdit()
{
}

