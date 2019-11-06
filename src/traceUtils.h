#pragma once

#define PRINT(message) \
            std::wcout<<message<<"\n";

#define PRINT_ERROR(error) \
            PRINT(winErrorUtils::GetErrorDescription(error).GetBuffer());
