#include <stdlib.h>;
#include <stdio.h>;
#include <string.h>;

int main() {

    int roundnum = 12;

    char infilename[14];
    sprintf(infilename,"round1%d.txt",roundnum);
    char outfilename[14];
    sprintf(outfilename,"round1%d.xml",roundnum);

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
    
    fprintf(out,"<round id='1%d'>\n",roundnum);

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
        else if(line[j]=='C')
            { 
                strcpy(subject,"chemistry"); 
                j+=10; 
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
            strcpy(line,line+3);
            line[strlen(line)-1]=0;
            fprintf(out,"        <w_choice>%s</w_choice>\n",line);

            fgets(line,10000,in);
            strcpy(line,line+3);
            line[strlen(line)-1]=0;
            fprintf(out,"        <x_choice>%s</x_choice>\n",line);

            fgets(line,10000,in);
            strcpy(line,line+3);
            line[strlen(line)-1]=0;
            fprintf(out,"        <y_choice>%s</y_choice>\n",line);

            fgets(line,10000,in);
            strcpy(line,line+3);
            line[strlen(line)-1]=0;
            fprintf(out,"        <z_choice>%s</z_choice>\n",line);

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
        else if(line[j]=='C')
            { 
                strcpy(subject,"chemistry"); 
                j+=10; 
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
            strcpy(line,line+3);
            line[strlen(line)-1]=0;
            fprintf(out,"        <w_choice>%s</w_choice>\n",line);

            fgets(line,10000,in);
            strcpy(line,line+3);
            line[strlen(line)-1]=0;
            fprintf(out,"        <x_choice>%s</x_choice>\n",line);

            fgets(line,10000,in);
            strcpy(line,line+3);
            line[strlen(line)-1]=0;
            fprintf(out,"        <y_choice>%s</y_choice>\n",line);

            fgets(line,10000,in);
            strcpy(line,line+3);
            line[strlen(line)-1]=0;
            fprintf(out,"        <z_choice>%s</z_choice>\n",line);

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


