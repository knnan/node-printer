#pragma once

namespace PrinterUtils
{
    //Changed printer settings with devmode and returned changed DEVMODE struct
    PDEVMODEW ChangePrinterProperties( IN CString& szPrinterName, IN PDEVMODE pSrcDevMode, IN HANDLE hPrinter );

    //Changed printer settings with devmode for current OS version.
    VOID ChangePrinterSettingsForCurrentOS( IN CString& szPrinterName, OUT PRINTER_INFO_2& pi2, IN DEVMODE& srcDevMode, IN HANDLE hPrinter );
    
    VOID DevmodeCopy( IN const DEVMODE& fromDevMode, OUT DEVMODE& toDevMode );

    BOOL SetPrinterSetting( IN CString& szPrinterName, IN DEVMODE& devMode );
};