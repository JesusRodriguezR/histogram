#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *image, *outputImage, *lecturas, *histo;
    image = fopen("sample3.bmp","rb");          //Imagen original a transformar
    outputImage = fopen("img2_dd.bmp","wb");    //Imagen transformada
    histo = fopen("histogram.txt","wb");
    long ancho;
    long alto;
    unsigned char r, g, b;               //Pixel
    unsigned char* ptr;

    unsigned char xx[54];
    int cuenta = 0;
    for(int i=0; i<54; i++) {
      xx[i] = fgetc(image);
      fputc(xx[i], outputImage);   //Copia cabecera a nueva imagen
    }
    ancho = (long)xx[20]*65536+(long)xx[19]*256+(long)xx[18];
    alto = (long)xx[24]*65536+(long)xx[23]*256+(long)xx[22];
    printf("largo img %li\n",alto);
    printf("ancho img %li\n",ancho);
    int pr[256],pg[256],pb[256];
    int cr,cg,cb;
    for(int i = 0;i<256;i++){
      pr[i] = 0;
      pg[i] = 0;
      pb[i] = 0;
    }
    ptr = (unsigned char*)malloc(alto*ancho*3* sizeof(unsigned char));

    while(!feof(image)){
      b = fgetc(image);
      g = fgetc(image);
      r = fgetc(image);

      pr[r]++;
      pb[b]++;
      pg[g]++; 




    }                                        //Grises


  for(int i = 0;i<256;i++){
    printf("%d\t %d\t %d\t \n", pr[i], pg[i], pb[i]);
    fprintf(histo, "%d\t %d\t %d\t \n", pr[i], pg[i], pb[i]);

  }
    free(ptr);
    fclose(image);
    fclose(outputImage);
    return 0;
}
