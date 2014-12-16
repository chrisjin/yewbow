#pragma once
#define NS_YB_BEGIN namespace yewbow {
#define NS_YB_END   }
#define YB_INTERFACE

#define YB_SINGLETON_DCLR(classname) \
public:\
	static classname* GetInstance();\
private:\
	static classname* m_OneInstance;\

#define YB_SINGLETON_IMPL(classname)\
	classname* classname::m_OneInstance =0;\
	classname* classname::GetInstance()\
				{\
			if(m_OneInstance)\
			return m_OneInstance;\
						else \
						{\
				m_OneInstance=new classname;\
				return m_OneInstance;\
						}\
				}

#define yb_vsprintf vsprintf_s
#define yb_fopen    fopen_s