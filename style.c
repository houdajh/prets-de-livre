#include "myfiles.h"

//-----------------------------------------style-----------------------------------------------------------------------------------------

void SetColor(int ForgC)
{
     WORD wColor;
     //This handle is needed to get the current background attribute

     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;
     //csbi is used for wAttributes word

     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
          //To mask out all but the background attribute, and to add the color
          wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
     return;
}







void bienvenue(){
SetColor(37);//Function call to change the text color
printf("     ````````      .-.\n");
printf("     /ssssssso+:` +yyy/   \n");
printf("     /ssso+oossso.-oso-   \n");
printf("     /sss/   /sss/`:::`  `````           -ooo.     :oo+`                 `///    .//:  `.---.`  \n");
printf("     /sss/  `/sss:-yyy--*******--+++./+oo+ooo+`   -ooo.*****  .ooo-/osso/-sss`   -ss+-/++++++++:`    \n");
printf("     /sssooossso- -yyyo/:.   .:+ooooo+//ooooso+` .ooo+:******.-yyyys+/oyyyyss`   -ssso+/.`  `-+++.   \n");
printf("     /sssssssssso::yyyo/*******+oooo-   `ooosoo/.ooo+:.`   `.-+yyy/    oyyyss`   -ssso+:::::::/+++`  \n");
printf("     /sss/  `./sssyyyyo/-*******:ooo     +oo/ooooooo:*********+yyy`    +yyyss-   /sss+/:::::::::::`  \n");
printf("     /sss/     ossyyyy****:-:****ooo     +oo:.oooo/.**.     ` -yyy`    +yyoossoooss+o++.     `.      \n");
printf("     /sss/``../sssyyyy. .*****. -ooo     +oo: .oo+` .***...***:yyy`    +yy+ .::/:-` ./++/:::/+++:    \n");
printf("     /ssssssssssso:***`         -oo+     /oo:         `******`.sss`    /ss/           .://///:-.     \n");
printf("     :ooooooo++:.    \n");

}





void emoji(){
SetColor(38);
printf("                                                                                         ``` \n");
printf("        `..--.                            ````..........````                           `--....   \n");
printf("       ..``.--`                       ``.....--------------...``                       ..-.``..    \n");
printf("       ..``.-..                     `...----:::--.-------------..`                     ..-.``.`     \n");
printf("       `.``.-..`                 ``..---::-----:/-.....--:::::----.`                  `..-.`..    \n");
printf("        `.`.....`               `..-..---..`````-::...-::-....-:----.`              `........     \n");
printf("         `.......``           `..---..-..``:+:` `.:-../-.`-/-```.----..          ``..`.....`     \n");
printf("            .....`....`      `..---..--..::hMMm.  .-.-:.-/hMMo  `.-----.`     `.-..``....`           \n");
printf("             .-...`...--`    ..----..--..dmNNmm-  `-.:-.:dddd+   .------.   `--..``...--.`           \n");
printf("         ``.-----...``..--  `.----...-:-.-+oo+-  `.-`-:...--. ```-------.` `--.```..------..``       \n");
printf("      ``..--:::::--.````.-.`.------...::-..``````.:.`.::...````.-:-------.`--.```..-:::::::--..`     \n");
printf("     `..----::::::--.```.--`.------....-:::-----:-.```.-:::--------------.`:-.```.--:-------.-...    \n");
printf("     ..........--:--.....--`.------...--::---...```````....---::-------:-.`---...-:----.........`    \n");
printf("     `...`.....---::-----:.`.--------::/+/:--.``````````...--:///:----::-.`-::---:::-----......`     \n");
printf("       `-...-----::::/::---`.-----------:/+:------------::--:/::::---:::-.`----:/::-----------`      \n");
printf("       `-..---------:::-.-. ..------------/ss/-----......:+s+-------::::-. .-.-:::---.........       \n");
printf("        `.......-----:::-.  `.--------------+ddyo/////oydmd/--:----::::-.`  `-::-------...-.`        \n");
printf("         `--.......---::`    `.--------------:+sssooossssy:--::--:::::-.`    `-----.......-.         \n");
printf("          `.......-----.      `.-----------:---::-..--:+/--:::-::::::-.`      `.-..----...`         \n");
printf("             `........         `.---------::::--.--------:/::::::::--.`          ```````           \n");
printf("                                 `.---------:::/::::::://::::::::--.`                             \n");
printf("                                   `.---:-::::::::::/::::::::::--.`                                \n");
printf("                                     ``..---:::::::::::::::---.``                                  \n");
printf("                                         ``...----------...``                                     \n");
printf("                                               ````````\n");


}



void merci(){
SetColor(36);//Function call to change the text color


printf("                            `\n");
printf("                +`         `s:                                                      \n");
printf("               `y/         +oo                                               :-   \n");
printf("               `o-/`      :o s`                                             ++`      \n");
printf("               `s .+`    .s` /:                                             :`       \n");
printf("                s  `+.  .s.  -o        ````..`     `....`                            \n");
printf("                s`  .o``o-   .s      /+//:::-.  `o/:::--:/     `-::`       .          \n");
printf("                o`   .++:    `y      s`         -s     `++    :+/.``       o`            \n");
printf("                +.    `.      s`     s          :+  `./+-   `o/`           +.              \n");
printf("                /:            o-    `y////      :s/+s+-    `s:             /:               \n");
printf("                :/            //    .o``        /o..-:/:`  :o              :/                 \n");
printf("                -+            -s    -+          /+     .+. -+`             -+                \n");
printf("                .o            `y    -o``...---. ::      -+  .:::::://      -/                 \n");
printf("                `o            `s`   `:--...``            `     ``````       `                  \n");
printf("                `/             `                                                                \n");




}





void livre_sty(){
    SetColor(38);//Function call to change the text color

printf("                                             ....          \n");
printf("                                         -/+++++oss:    \n");
printf("                                      -/o+:::://+sysoooooooooooooo+++++++++++++++////////////+/    \n");
printf("                                  `-/+/::://+osso/////////////:::::::::::::::::::::::::::::oyhm     \n");
printf("                               .:/+/:://++sss++//////////////::::::::::::::::::::::::::::oyyyy/   \n");
printf("                           `-/+//://++osso+//////////////////:::::::::::::::::::::::::/oyyyd/`    \n");
printf("                        .:/+/:://+ossso+//////////////////////::::::::::::::::::::::/ohyyyd:       \n");
printf("                    `-:+//://++osss++/////////////////////////::::::::::::::::::::/syyyy+o+         \n");
printf("                 .:/+////++ossso+++//////////////////////////:::::::::::::::::::/syyhy+::d.         \n");
printf("             `-:+////+++ossso++++++//////////////////////////:::::::::::::::::+syyyy+::--m.         \n");
printf("          ./ooo+++++osssso+++++++++///////////////////////////::::::::::::::+yyyyy+::---.y+         \n");
printf("        :sssooossyhhhso++++++++++++//////////////////////////:::::::::::::+yysyy+::---....d/:-      \n");
printf("       +sosyyyyysyyosyyyysso++++++++/////////////////////////::::::::::/oyysyy+::---...``.yydh      \n");
printf("      +soyhyyyym+osysssssssyyyysso++/////////////////////////::::::::/oyssys+::---...```:syhhy      \n");
printf("     -hosmyyyydyo::://+oyyyyyssyyyhhysso+////////////////////::::::/ossoss+::---...````+yhhh+`      \n");
printf("     yoodhyyyydss---:::::://osyyyhyyyyhhhhysoo+//////////////::::/osooss+::---...``` -syhhy:       \n");
printf("     m++mysssohsy---------::::::/+osyhhhyyyyhhhhysoo+/////://::+sso+ss+::---...``` `/syhhs.        \n");
printf("     mo+dyoo++yso...-----------:::::::/+oyyhhhyyyyhhhhyso++//+so++os/::---...```  .oyhhh/          \n");
printf("     yh+sd+///yh-........----------::::::::/++oyyyhyyyyyyyyyd+//oo/::---...```   :syhhy-           \n");
printf("     .ds/sho/ss/``````.........----------::::::::/++syyyyyysN/+o/::---...```   `oshhho`           \n");
printf("      .yyo+sdddy+-.````````.........-----------::::::::/+ohhds/::---...```    -syhhy:             \n");
printf("        ./+shyhyddyy+-.``````````.........----------:::::+s::::---...```    `+syhhs.              \n");
printf("            .-/syyhyhdyy+-.`  ````````.........---------:h:::---...```     -sshhh+                \n");
printf("                `-+syyhyhdhso:.`   ````````.........----oo:---...```     `/syhyy-                \n");
printf("                    .:+yyyyhhdhso:.`     ````````.......so--...```      .oshhho`                 \n");
printf("                        .:oyyyyhhdhso:.`      ````````../s...```       :sshhh/                   \n");
printf("                            ./oyyyyhhhhss/.`       `````.d.```       `osyhyy.                   \n");
printf("                                ./oyyyyhhhhys/-`         /s``       -sshhho`                     \n");
printf("                                    -/oyyyyhhhhys+-`      s/      `+syhyy:                         \n");
printf("                                       `-/syyyyhhhhys+-``  y/    .sshhhs`                         \n");
printf("                                           `-+syyyyhhhhyso:.s+  /sshyh/                          \n");
printf("                                               `:+syysyhhhhysmyosyhyy-                            \n");
printf("                                                   `:+yyysyhhhhshyho`                            \n");
printf("                                                       `:+yyysyNyh:                             \n");
printf("                                                           `:oymy.                              \n");
printf("                                                               `                                \n");

}

