// EMFTest.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
//
#include "Emf2Pdf.h"
#include <csetjmp>
#include <hpdf.h>
#include <hpdf_types.h>
static jmp_buf env;
void error_handler(HPDF_STATUS error_no, HPDF_STATUS detail_no, void *user_data)
{
    printf("ERROR: error_no=%04X, detail_no=%d\n", (unsigned int)error_no, (int)detail_no);
    longjmp(env, 1); /* invoke longjmp() on error */
}
int main(int argc, const char *argv[])
{ /*
     HPDF_Doc pdf = HPDF_New(0, 0);
     Emf2Pdf conv(pdf);
     conv.AddEMF("rep01.emf");
     if (HPDF_GetError(pdf) == HPDF_OK) conv.AddEMF("261465000.emf");
     //if (HPDF_GetError(pdf) == HPDF_OK) conv.AddEMF("rep02.emf");
     //if (HPDF_GetError(pdf) == HPDF_OK) conv.AddEMF("rep03.emf");
     //if (HPDF_GetError(pdf) == HPDF_OK) conv.AddEMF("rep04.emf");
     //if (HPDF_GetError(pdf) == HPDF_OK) conv.AddEMF("rep05.emf");
     //if (HPDF_GetError(pdf) == HPDF_OK) conv.AddEMF("rep06.emf");
     if (HPDF_GetError(pdf) == HPDF_OK) HPDF_SaveToFile(pdf, "rep.pdf");

     /*/
    const char *fileToOpen;
    fileToOpen = "PAGINA.emf";
    if (argc > 1)
        fileToOpen = argv[1];
    HPDF_Doc pdf = HPDF_New(error_handler, NULL);
    Emf2Pdf conv(pdf);
    conv.AddEMF(fileToOpen);
    HPDF_STATUS stat = HPDF_GetError(pdf);
    if (pdf)
    {
        size_t l = strlen(fileToOpen);
        char *fileToSave = (char *)malloc(l + 2);
        strcpy_s(fileToSave, l + 2, fileToOpen);
        char *extension = strrchr(fileToSave, (int)'.');
        strcpy_s(extension, 5, ".pdf");
        stat = HPDF_SaveToFile(pdf, fileToSave);
        printf("File salvato in %s, stat = %d\r\n", fileToSave, stat);
    } //*/
}
