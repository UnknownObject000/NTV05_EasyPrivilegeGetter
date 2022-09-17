// NTV_05_RtlAdjustPrivilege.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <Windows.h>

//准备函数指针
typedef UINT(CALLBACK* typeRtlAdjustPrivilege)(ULONG, BOOL, BOOL, PINT);

//从ntdll.dll中获取函数，封装API
UINT RtlAdjustPrivilege(ULONG Privilege, BOOL bEnablePrivilege, BOOL IsThreadPrivilege, PINT PreviousValue)
{
	HMODULE hDll = GetModuleHandle(L"ntdll.dll");
	if (hDll == NULL)
		return false;
	typeRtlAdjustPrivilege func_RtlAdjustPrivilege = (typeRtlAdjustPrivilege)GetProcAddress(hDll, "RtlAdjustPrivilege");
	return func_RtlAdjustPrivilege(Privilege, bEnablePrivilege, IsThreadPrivilege, PreviousValue);
}

//API函数的调用（以获取SeShutdownPrivilege为例）
void NtGetShutdown()
{
	int nEn = 0;
	LUID luidPriv;
	LookupPrivilegeValue(NULL, SE_SHUTDOWN_NAME, &luidPriv);
	RtlAdjustPrivilege(luidPriv.LowPart, TRUE, FALSE, &nEn);
	return;
}

//测试用主函数——尝试关闭计算机
int main()
{
	NtGetShutdown();
	ExitWindowsEx(EWX_SHUTDOWN, 0);
	return 0;
}