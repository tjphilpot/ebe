.nolist
.macro frame currpars, locals, newpars
    .equ    xp, \locals
    .ifgt   \newpars-6
        .equ    xp, xp+\newpars-6
    .endif
    .equ    xp, (xp+1)/2*2
    .equ    frame_size, xp*8
.endm

.equ newPar7, 0
.equ newPar8, 8
.equ newPar9, 16
.equ newPar10, 24
.equ newPar11, 32
.equ newPar12, 40
.equ newPar13, 48
.equ newPar14, 56
.equ newPar15, 64
.equ newPar16, 72
.equ newPar17, 80
.equ newPar18, 88
.equ newPar19, 96
.equ newPar20, 104
.equ newPar21, 112
.equ newPar22, 120
.equ newPar23, 128
.equ newPar24, 136
.equ newPar25, 144
.equ newPar26, 152
.equ newPar27, 160
.equ newPar28, 168
.equ newPar29, 176
.equ newPar30, 184
.equ newPar31, 192
.equ newPar32, 200
.equ newPar33, 208
.equ newPar34, 216
.equ newPar35, 224
.equ newPar36, 232
.equ newPar37, 240
.equ newPar38, 248
.equ newPar39, 256
.equ newPar40, 264
.equ newPar41, 272
.equ newPar42, 280
.equ newPar43, 288
.equ newPar44, 296
.equ newPar45, 304
.equ newPar46, 312
.equ newPar47, 320
.equ newPar48, 328
.equ newPar49, 336
.equ newPar50, 344
.equ newPar51, 352
.equ newPar52, 360
.equ newPar53, 368
.equ newPar54, 376
.equ newPar55, 384
.equ newPar56, 392
.equ newPar57, 400
.equ newPar58, 408
.equ newPar59, 416
.equ newPar60, 424
.equ newPar61, 432
.equ newPar62, 440
.equ newPar63, 448
.equ newPar64, 456
.equ newPar65, 464
.equ newPar66, 472
.equ newPar67, 480
.equ newPar68, 488
.equ newPar69, 496
.equ newPar70, 504
.equ newPar71, 512
.equ newPar72, 520
.equ newPar73, 528
.equ newPar74, 536
.equ newPar75, 544
.equ newPar76, 552
.equ newPar77, 560
.equ newPar78, 568
.equ newPar79, 576
.equ newPar80, 584
.equ newPar81, 592
.equ newPar82, 600
.equ newPar83, 608
.equ newPar84, 616
.equ newPar85, 624
.equ newPar86, 632
.equ newPar87, 640
.equ newPar88, 648
.equ newPar89, 656
.equ newPar90, 664
.equ newPar91, 672
.equ newPar92, 680
.equ newPar93, 688
.equ newPar94, 696
.equ newPar95, 704
.equ newPar96, 712
.equ newPar97, 720
.equ newPar98, 728
.equ newPar99, 736
.equ newPar100, 744
.equ local1, -8
.equ local2, -16
.equ local3, -24
.equ local4, -32
.equ local5, -40
.equ local6, -48
.equ local7, -56
.equ local8, -64
.equ local9, -72
.equ local10, -80
.equ local11, -88
.equ local12, -96
.equ local13, -104
.equ local14, -112
.equ local15, -120
.equ local16, -128
.equ local17, -136
.equ local18, -144
.equ local19, -152
.equ local20, -160
.equ local21, -168
.equ local22, -176
.equ local23, -184
.equ local24, -192
.equ local25, -200
.equ local26, -208
.equ local27, -216
.equ local28, -224
.equ local29, -232
.equ local30, -240
.equ local31, -248
.equ local32, -256
.equ local33, -264
.equ local34, -272
.equ local35, -280
.equ local36, -288
.equ local37, -296
.equ local38, -304
.equ local39, -312
.equ local40, -320
.equ local41, -328
.equ local42, -336
.equ local43, -344
.equ local44, -352
.equ local45, -360
.equ local46, -368
.equ local47, -376
.equ local48, -384
.equ local49, -392
.equ local50, -400
.equ local51, -408
.equ local52, -416
.equ local53, -424
.equ local54, -432
.equ local55, -440
.equ local56, -448
.equ local57, -456
.equ local58, -464
.equ local59, -472
.equ local60, -480
.equ local61, -488
.equ local62, -496
.equ local63, -504
.equ local64, -512
.equ local65, -520
.equ local66, -528
.equ local67, -536
.equ local68, -544
.equ local69, -552
.equ local70, -560
.equ local71, -568
.equ local72, -576
.equ local73, -584
.equ local74, -592
.equ local75, -600
.equ local76, -608
.equ local77, -616
.equ local78, -624
.equ local79, -632
.equ local80, -640
.equ local81, -648
.equ local82, -656
.equ local83, -664
.equ local84, -672
.equ local85, -680
.equ local86, -688
.equ local87, -696
.equ local88, -704
.equ local89, -712
.equ local90, -720
.equ local91, -728
.equ local92, -736
.equ local93, -744
.equ local94, -752
.equ local95, -760
.equ local96, -768
.equ local97, -776
.equ local98, -784
.equ local99, -792
.equ local100, -800
.equ currPar7, 16
.equ currPar8, 24
.equ currPar9, 32
.equ currPar10, 40
.equ currPar11, 48
.equ currPar12, 56
.equ currPar13, 64
.equ currPar14, 72
.equ currPar15, 80
.equ currPar16, 88
.equ currPar17, 96
.equ currPar18, 104
.equ currPar19, 112
.equ currPar20, 120
.equ currPar21, 128
.equ currPar22, 136
.equ currPar23, 144
.equ currPar24, 152
.equ currPar25, 160
.equ currPar26, 168
.equ currPar27, 176
.equ currPar28, 184
.equ currPar29, 192
.equ currPar30, 200
.equ currPar31, 208
.equ currPar32, 216
.equ currPar33, 224
.equ currPar34, 232
.equ currPar35, 240
.equ currPar36, 248
.equ currPar37, 256
.equ currPar38, 264
.equ currPar39, 272
.equ currPar40, 280
.equ currPar41, 288
.equ currPar42, 296
.equ currPar43, 304
.equ currPar44, 312
.equ currPar45, 320
.equ currPar46, 328
.equ currPar47, 336
.equ currPar48, 344
.equ currPar49, 352
.equ currPar50, 360
.equ currPar51, 368
.equ currPar52, 376
.equ currPar53, 384
.equ currPar54, 392
.equ currPar55, 400
.equ currPar56, 408
.equ currPar57, 416
.equ currPar58, 424
.equ currPar59, 432
.equ currPar60, 440
.equ currPar61, 448
.equ currPar62, 456
.equ currPar63, 464
.equ currPar64, 472
.equ currPar65, 480
.equ currPar66, 488
.equ currPar67, 496
.equ currPar68, 504
.equ currPar69, 512
.equ currPar70, 520
.equ currPar71, 528
.equ currPar72, 536
.equ currPar73, 544
.equ currPar74, 552
.equ currPar75, 560
.equ currPar76, 568
.equ currPar77, 576
.equ currPar78, 584
.equ currPar79, 592
.equ currPar80, 600
.equ currPar81, 608
.equ currPar82, 616
.equ currPar83, 624
.equ currPar84, 632
.equ currPar85, 640
.equ currPar86, 648
.equ currPar87, 656
.equ currPar88, 664
.equ currPar89, 672
.equ currPar90, 680
.equ currPar91, 688
.equ currPar92, 696
.equ currPar93, 704
.equ currPar94, 712
.equ currPar95, 720
.equ currPar96, 728
.equ currPar97, 736
.equ currPar98, 744
.equ currPar99, 752
.equ currPar100, 760
.list
