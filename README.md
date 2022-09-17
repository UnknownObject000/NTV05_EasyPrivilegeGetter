# NTV05_EasyPrivilegeGetter
NTAPI简单提权函数视频源代码，用于演示未公开的NtAPI - RtlAdjustPrivilege

## RtlAdjustPrivilege

### 函数原型
```c++
UINT RtlAdjustPrivilege(ULONG Privilege, BOOL bEnablePrivilege, BOOL IsThreadPrivilege, PINT PreviousValue);
```

### 函数指针类型
```c++
typedef UINT(CALLBACK* typeRtlAdjustPrivilege)(ULONG, BOOL, BOOL, PINT);
```

### 所在DLL
 - ntdll.dll

