#pragma once
#include <jni.h>
#include <AstronomicalBodyJavaHelper.h>

namespace JavaUtils {
	class SunJavaHelper : public AstronomicalBodyJavaHelper {
		public:
			SunJavaHelper(JNIEnv* env);
			~SunJavaHelper();
	};
}
