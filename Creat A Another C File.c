#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<dir.h>

void mf();
void cf();


int main()
{
    FILE *te;
    int c, s, e;
    char ch[10000], cx[10], cha[10000], chatem[10000], dccc[3];
AA:
    printf("Enter Path:  ");
    gets(cha);
CHEAKING:
    strcpy(chatem, cha);
    strcat(chatem, "\\text.txt");

    te=fopen(chatem, "w");
    if(!te)
    {
        printf("No Folder Found...\nWant To Creat New Folder? (Y/N):  ");
AAA:
        scanf("%s", dccc);
        switch (dccc[0])
        {
        case 'Y':
            cf(cha);
            goto CHEAKING;
            break;

        case 'N':
            getchar();
            goto AA;
            break;

        default:
            printf("Wrong Input. Press Y to creat new folder, press N to re-enter path:  ");
            goto AAA;
        }
    }

    fclose(te);
    remove(chatem);

    printf("Enter File Name:  ");
    gets(ch);

    printf("Enter Extension: ");
    gets(cx);

A:
    printf("Starting Point:  ");
    scanf("%d", &s);

    printf("Ending Point:  ");
    scanf("%d", &e);

    if(s>e)
    {
        printf("Invalid\n\n");
        goto A;
    }

    for(c=s; c<=e; c++)
        mf(ch, cx, cha, c);

    return 0;
}

void mf(char ch[], char cx[], char cha[], int c)
{
    FILE *fp;
    char tem[10000];
    char chatemp[99999];

    strcpy(chatemp, cha);
    strcat(chatemp, "\\");
    strcat(chatemp, ch);

    sprintf(tem, "%04d", c);
    strcat(chatemp, tem);

    strcat(chatemp, cx);

    fp=fopen(chatemp, "w");
    fprintf(fp, "<?xml version=\"1.0\"?>\n<WLANProfile xmlns=\"http://www.microsoft.com/networking/WLAN/profile/v1\">\n	<name>\\\\\\\\\\\\\\\\\</name>\n	<SSIDConfig>\n		<SSID>\n			<name>\\\\\\\\\\\\\\\</name>\n		</SSID>\n	</SSIDConfig>\n	<connectionType>ESS</connectionType>\n	<connectionMode>auto</connectionMode>\n	<MSM>\n		<security>\n			<authEncryption>\n				<authentication>\\\\\\\\\\\\\\</authentication>\n				<encryption>AES</encryption>\n				<useOneX>false</useOneX>\n			</authEncryption>\n			<sharedKey>\n				<keyType>passPhrase</keyType>\n				<protected>false</protected>\n				<keyMaterial>\\\\\\\\\</keyMaterial>\n			</sharedKey>\n		</security>\n	</MSM>\n	<MacRandomization xmlns=\"http://www.microsoft.com/networking/WLAN/profile/v3\">\n		<enableRandomization>false</enableRandomization>\n	</MacRandomization>\n</WLANProfile>\n");
    fclose(fp);

    puts(chatemp);
    printf("\n");
}

void cf(char cha[])
{
    int check;

    check=mkdir(cha);

    getchar();

    if(!check)
        printf("Directory created\n");
    else
        printf("Unable to create directory\n");
}

