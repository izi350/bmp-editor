
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
//vvodim biblioteki
typedef struct
{
unsigned char b;
unsigned char g;
unsigned char r;

} PIXEL;

PIXEL rastr[1000][1000]; ]; ]; // Присваивание каждому элементу массива "rastr" структуры PIXEL

BITMAPFILEHEADER h1;

BITMAPINFOHEADER h2;

int sz;

const char *infile = "1.bmp";

const char *outfile1 = "2.bmp";

const char *outfile2 = "3.bmp";

const char *outfile3 = "4.bmp";

const char *outfile4 = "5.bmp";

FILE *fr , *fw ;

int sz_padding; ; // инициализация переменной для значения размера "набивки"

char padding;

int read_file()

{

int i,j;

fr = fopen(infile , "r");// Чтение и запись открываемого файла в переменную fr

perror("open infile");// Проверка открылся файл или нет

fread(&h1 , sizeof(h1) , 1 , fr); // Потоковое чтение и запись структуры BITMAPFILEHEADER открываемого файла в переменную h1

fread(&h2 , sizeof(h2) , 1 , fr); ); // Потоковое чтение и запись структуры BITMAPINFOHEADER открываемого файла в переменную h2

sz_padding = (h2.biSizeImage - h2.biHeight * h2.biWidth * 3)/h2.biHeight; Из полного размера изображения вычитаем полезную информацию и делим результат на количество строк. Получаем сколько бесполезной информации в каждой строке.

for ( i = 0 ; i < h2.biHeight ; i++ )

{

for ( j = 0 ; j < h2.biWidth ; j++ )

fread( &rastr[i][j] , 1 , 3 , fr );//Запись пикселей

fread( &padding , 1 , sz_padding , fr );

}

return 0;

}

int change_head()

{

h2.biHeight=h2.biHeight/2; //Уменьшение высоты в два раза

h2.biWidth=h2.biWidth/2; ; //Уменьшение ширины в два раза

return 0;

}

int write_file1()

{

int i,j;

fw = fopen(outfile1 , "w");

perror("open outfile1");

fwrite(&h1 , sizeof(h1) , 1 , fw);

fwrite(&h2 , sizeof(h2) , 1 , fw);

for ( i = 0 ; i < h2.biHeight ; i++ )

{

for ( j = 0 ; j < h2.biWidth ; j++ )

fwrite( &rastr[i][j] , 1 , 3 , fw );

fwrite( &padding , 1 , sz_padding , fw );

}

return 0;

}

int write_file2()

{

int i,j;

fw = fopen(outfile2 , "w");

perror("open outfile2");

fwrite(&h1 , sizeof(h1) , 1 , fw);

fwrite(&h2 , sizeof(h2) , 1 , fw);

for ( i =h2.biHeight ; i < h2.biHeight*2 ; i++ )

{

for ( j = 0 ; j < h2.biWidth ; j++ )

fwrite( &rastr[i][j] , 1 , 3 , fw );

fwrite( &padding , 1 , sz_padding , fw );

}

return 0;

}

int write_file3()

{

int i,j;

fw = fopen(outfile3 , "w");

perror("open outfile3");

fwrite(&h1 , sizeof(h1) , 1 , fw);

fwrite(&h2 , sizeof(h2) , 1 , fw);

for ( i = 0 ; i < h2.biHeight ; i++ )

{

for ( j = h2.biWidth ; j < h2.biWidth*2 ; j++ )

fwrite( &rastr[i][j] , 1 , 3 , fw );

fwrite( &padding , 1 , sz_padding , fw );

}

return 0;

}

int write_file4()

{

int i,j;

fw = fopen(outfile4 , "w");

perror("open outfile4");

fwrite(&h1 , sizeof(h1) , 1 , fw);

fwrite(&h2 , sizeof(h2) , 1 , fw);

for ( i =h2.biHeight ; i < h2.biHeight*2 ; i++ )

{

for ( j = h2.biWidth ; j < h2.biWidth*2 ; j++ )

fwrite( &rastr[i][j] , 1 , 3 , fw );

fwrite( &padding , 1 , sz_padding , fw );

}

return 0;

}

int main()

{

read_file();

change_head();

write_file1();

write_file2();

write_file3();

write_file4();

return 0;

}
