#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
    //Your printer name
    CString testPrinter(L"Your printer name");    

    //The DEVMODE data structure contains information about the initialization and environment of a printer     
    DEVMODE   devmodeIn    = {0};                    
    PDEVMODE  pDevmodeWork = NULL;              

    // Get current printer properties
    pDevmodeWork = PrinterUtils::ChangePrinterProperties(testPrinter, &devmodeIn, NULL);

    if( !pDevmodeWork )
    {
         PRINT(_T("Can't get printer settings"));
         return 0;
    }
        

    // Change some fields        

    // Check if driver support this change
    if( pDevmodeWork->dmFields & DM_COPIES )
    {
        //Selects the number of copies printed if the device supports multiple-page copies. 
        pDevmodeWork->dmCopies = 3;  
        //Indicate which parameter was changed 
        pDevmodeWork->dmFields |= DM_COPIES;         
    }

    if( pDevmodeWork->dmFields & DM_ORIENTATION )
    {
        pDevmodeWork->dmOrientation = DMORIENT_LANDSCAPE;
        pDevmodeWork->dmFields |= DM_ORIENTATION;
    }

    if( pDevmodeWork->dmFields & DM_PAPERSIZE )
    {
        pDevmodeWork->dmPaperSize = DMPAPER_A3;
        pDevmodeWork->dmFields |= DM_PAPERSIZE;
    }

    if( pDevmodeWork->dmFields & DM_PRINTQUALITY )
    {
        pDevmodeWork->dmPrintQuality = DMRES_HIGH;
        pDevmodeWork->dmFields |= DM_PRINTQUALITY;
    }

    if( pDevmodeWork->dmFields & DM_COLOR )
    {
        pDevmodeWork->dmColor = DMCOLOR_COLOR;
        pDevmodeWork->dmFields |= DM_COLOR;
    }


    //Setting printer settings 
    if( !PrinterUtils::SetPrinterSetting(testPrinter, *pDevmodeWork) )
    {
        PRINT(_T("Can't set printer settings"));
    }
    else
    {
        PRINT(_T("SetPrinterSetting Ok"));
    }


    ::free(pDevmodeWork);

    return 0;
}

