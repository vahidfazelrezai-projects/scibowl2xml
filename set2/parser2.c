/* using these websites:
http://www.convertpdftotext.net
http://www.textfixer.com/tools/remove-line-breaks.php
http://textmechanic.com/Remove-Extra-Spaces.html
http://textmechanic.com/Remove-Empty-Lines.html
*/

#include <stdlib.h>;
#include <stdio.h>;
#include <string.h>;

int main() {

    char roundnum[] = "17";

    char roundnum1 = roundnum[0];
    char roundnum2 = roundnum[1];

    char infilename[14];
    sprintf(infilename,"round2%c%c.txt",roundnum1,roundnum2);
    char outfilename[14];
    sprintf(outfilename,"round2%c%c.xml",roundnum1,roundnum2);

    FILE *in = fopen(infilename,"r");
    FILE *out = fopen(outfilename,"w");

    int i;
    int j;
    int k;
    
    char line[10000];
    char subject[20];
    char type[20];
    char question[10000];
    char answer[10000];
    
    fprintf(out,"<round id='2%c%c'>\n",roundnum1,roundnum2);

    for(i=0; i<25; i++) {

        fprintf(out,"    <fullq num='%d' level='toss_up'>\n",i+1);

        fgets (line,10000,in);
        fgets (line,10000,in);    

        j=0;
        while(line[j]!=')') {
            j++;
        }
        j++;
        j++;

        //chooses right subject
        if(line[j]=='A')
            { 
                strcpy(subject,"earth_space");
                j+=10; 
            }
        else if(line[j]=='B')
            { 
                strcpy(subject,"biology"); 
                j+=8; 
            }
        else if(line[j+2]=='E')
            { 
                strcpy(subject,"chemistry"); 
                j+=10; 
            }
        else if(line[j+1]=='O')
            { 
                strcpy(subject,"general"); 
                j+=17; 
            }
        else if(line[j]=='E')
            { 
                strcpy(subject,"earth_space"); 
                j+=14; 
            }
        else if(line[j]=='G')
            { 
                strcpy(subject,"general"); 
                j+=16;
            }
        else if(line[j]=='M')
            { 
                strcpy(subject,"math"); 
                j+=5;
            }
        else if(line[j]=='P')
            { 
                strcpy(subject,"physics"); 
                j+=8;
            }


        fprintf(out,"        <subject>%s</subject>\n",subject);

        if(line[j]=='M')
        {
            strcpy(type,"multiple_choice");
            j+=16;
        }
        else
        {
            strcpy(type,"short_answer");
            j+=13;
        }

        fprintf(out,"        <type>%s</type>\n",type);

        strcpy(question,"");
        strcpy(question,line+j);
        question[strlen(question)-1]=0;

        fprintf(out,"        <question>%s</question>\n",question);

        if(type[0]=='s')
        {
            fgets (line,10000,in);
            
            strcpy(answer,"");
            strcpy(answer,line+8);
            answer[strlen(answer)-1]=0;
            
            fprintf(out,"        <answer>%s</answer>\n",answer);
        }
        else
        {
            fgets(line,10000,in);

            j=0;

            j+=3;

            fprintf(out,"        <w_choice>");
            while(!((line[j]=='X')&&(line[j+1]==')')&&(line[j+2]==' ')))
            {
                fprintf(out,"%c",line[j]);
                j++;
            }
            fprintf(out,"</w_choice>\n");

            j+=3;
            
            fprintf(out,"        <x_choice>");
            while(!((line[j]=='Y')&&(line[j+1]==')')&&(line[j+2]==' ')))
            {
                fprintf(out,"%c",line[j]);
                j++;
            }
            fprintf(out,"</x_choice>\n");

            j+=3;
            
            fprintf(out,"        <y_choice>");
            while(!((line[j]=='Z')&&(line[j+1]==')')&&(line[j+2]==' ')))
            {
                fprintf(out,"%c",line[j]);
                j++;
            }
            fprintf(out,"</y_choice>\n");
            
            j+=3;
            
            fprintf(out,"        <z_choice>");
            while(!(line[j]=='\n'))
            {
                fprintf(out,"%c",line[j]);
                j++;
            }
            fprintf(out,"</z_choice>\n");

            fgets(line,10000,in);
            strcpy(line,line+8);
            fprintf(out,"        <answer_choice>%c</answer_choice>\n",line[0]);

        }

        
        fprintf(out,"    </fullq>\n",i+1);







        // COPIED BELOW FOR BONUS




        fprintf(out,"    <fullq num='%d' level='bonus'>\n",i+1);

        fgets (line,10000,in);
        fgets (line,10000,in);    

        j=0;
        while(line[j]!=')') {
            j++;
        }
        j++;
        j++;

        //chooses right subject
        if(line[j]=='A')
            { 
                strcpy(subject,"earth_space");
                j+=10; 
            }
        else if(line[j]=='B')
            { 
                strcpy(subject,"biology"); 
                j+=8; 
            }
        else if(line[j+2]=='E')
            { 
                strcpy(subject,"chemistry"); 
                j+=10; 
            }
        else if(line[j+1]=='O')
            { 
                strcpy(subject,"general"); 
                j+=17; 
            }
        else if(line[j]=='E')
            { 
                strcpy(subject,"earth_space"); 
                j+=14; 
            }
        else if(line[j]=='G')
            { 
                strcpy(subject,"general"); 
                j+=16;
            }
        else if(line[j]=='M')
            { 
                strcpy(subject,"math"); 
                j+=5;
            }
        else if(line[j]=='P')
            { 
                strcpy(subject,"physics"); 
                j+=8;
            }


        fprintf(out,"        <subject>%s</subject>\n",subject);

        if(line[j]=='M')
        {
            strcpy(type,"multiple_choice");
            j+=16;
        }
        else
        {
            strcpy(type,"short_answer");
            j+=13;
        }

        fprintf(out,"        <type>%s</type>\n",type);

        strcpy(question,"");
        strcpy(question,line+j);
        question[strlen(question)-1]=0;

        fprintf(out,"        <question>%s</question>\n",question);

        if(type[0]=='s')
        {
            fgets (line,10000,in);
            
            strcpy(answer,"");
            strcpy(answer,line+8);
            answer[strlen(answer)-1]=0;
            
            fprintf(out,"        <answer>%s</answer>\n",answer);
        }
        else
        {
            fgets(line,10000,in);

            j=0;

            j+=3;

            fprintf(out,"        <w_choice>");
            while(!((line[j]=='X')&&(line[j+1]==')')&&(line[j+2]==' ')))
            {
                fprintf(out,"%c",line[j]);
                j++;
            }
            fprintf(out,"</w_choice>\n");

            j+=3;
            
            fprintf(out,"        <x_choice>");
            while(!((line[j]=='Y')&&(line[j+1]==')')&&(line[j+2]==' ')))
            {
                fprintf(out,"%c",line[j]);
                j++;
            }
            fprintf(out,"</x_choice>\n");

            j+=3;
            
            fprintf(out,"        <y_choice>");
            while(!((line[j]=='Z')&&(line[j+1]==')')&&(line[j+2]==' ')))
            {
                fprintf(out,"%c",line[j]);
                j++;
            }
            fprintf(out,"</y_choice>\n");
            
            j+=3;
            
            fprintf(out,"        <z_choice>");
            while(!(line[j]=='\n'))
            {
                fprintf(out,"%c",line[j]);
                j++;
            }
            fprintf(out,"</z_choice>\n");

            fgets(line,10000,in);
            strcpy(line,line+8);
            fprintf(out,"        <answer_choice>%c</answer_choice>\n",line[0]);

        }

        
        fprintf(out,"    </fullq>\n\n",i+1);

        
    }

    fprintf(out,"</round>",i+1);

    fclose(in);
    fclose(out);

}


