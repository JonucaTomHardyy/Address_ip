#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void start(char titre[]);

void end();

int main(){
    printf("content_type: text/html\n\n");

    start("DETERMINE LE CLASSE D'ADRESSE IPv4");

    char *chaine = NULL,
         ip1[5],
         ip2[5],
         ip3[5],
         ip4[5],
         *ch_nv = NULL;

    chaine = getenv("QUERY_STRING");
    sscanf(chaine, "IPv4=%[^.].%[^.].%[^.].%[^.]", ip1, ip2, ip3, ip4);
    //printf("%s.%s.%s.%s\n", ip1, ip2, ip3, ip4);

    printf("<DIV>");
    if(atoi(ip1) > 255 || atoi(ip2) > 255 || atoi(ip3) > 255 || atoi(ip4) > 255){
        printf("<P>cette ip est non valide</P>\n");
    }
    else if(atoi(ip1) <= 127){
        printf("<P>cette addresse ip de classe A</P>\n");
    }
    else if(atoi(ip1) <=191 ){
        printf("<P>cette addresse ip de classe B</P>\n");
    }
    else if(atoi(ip1) <= 223){
        printf("<P>cette addresse ip de classe C</P>\n");
    }
    else if(atoi(ip1) <= 239){
        printf("<P>cette addresse ip de classe D</P>\n");
    }
    else if(atoi(ip1) <= 255){
        printf("<P>cette addresse ip de classe E</P>\n");
    }

    printf("<A HREF=\"ipv4.html\">une autre</A>");

    printf("</DIV>");

    end();
    return 0;
}
/*____________________________________________________________________________*/

void start(char titre[]){
    //printf("content_type: text/html\n\n");


    printf("<!DOCTYPE html>\n");
    printf("<HTML>\n");
    printf("\t<HEAD>\n");
    printf("\t\t<TITLE>%s</TITLE>\n",titre);
    printf("\t\t<META charset=\"utf-8\">\n");
    printf("\t\t<LINK REL=\"stylesheet\" HREF=\"main.css\">");
    printf("\t</HEAD>\n");
    printf("\t<BODY>\n");
}
/*____________________________________________________________________________*/

void end(){
    printf("\t</BODY>\n");
    printf("</HTML>\n");
}
/*____________________________________________________________________________*/