#pragma once

namespace winErrorUtils
{
    inline CString GetErrorDescription( DWORD dwErrorCode )
    {
        ATL::CHeapPtr<WCHAR, ATL::CLocalAllocator> message;
        ATL::CString str;

        if (0 == ::FormatMessage(
            FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
            NULL,
            dwErrorCode,
            0,
            reinterpret_cast<LPWSTR>(&message.m_pData),
            0,
            NULL))
        {
            str.Format(L"Unknown error 0x%8.8X", dwErrorCode);
        }
        else
        {
            str = message;

            int nLen = str.GetLength();
            while (nLen > 0 && (str[nLen-1] == '\r' || str[nLen-1] == '\n'))
            {
                nLen--;
            }
            str.Truncate(nLen);
        }

        return str;
    }

}