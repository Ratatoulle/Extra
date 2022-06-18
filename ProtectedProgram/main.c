#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

int main()
{
	HKEY h;
	DWORD value = 0;
	DWORD buff = 4;
	char* path = TEXT("COUNT");
	if (RegCreateKeyEx(HKEY_CURRENT_USER, path, NULL, NULL, 0x00000001L, KEY_ALL_ACCESS, NULL, &h, NULL) == ERROR_SUCCESS)
	{
		if (RegQueryValueEx(h, path, NULL, NULL, &value, &buff) == ERROR_SUCCESS)
		{
			if (value > 0)
				return 0;
			value++;
			RegSetValueEx(h, path, NULL, REG_QWORD, &value, 4);
		}
		else
		{
			RegSetValueEx(h, path, NULL, REG_QWORD, &value, 4);
			value++;
			printf_s("Start");
		}
	}
	if (RegQueryValueEx(h, path, NULL, NULL, &value, &buff) == ERROR_SUCCESS)
	{
		value = 0;
		RegSetValueEx(h, path, NULL, REG_DWORD, &value, 4);
	}
	return 0;
}