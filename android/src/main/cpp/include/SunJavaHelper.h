#pragma once
#include <jni.h>
#include <PlanetJavaHelper.h>

namespace JavaUtils {
	class SunJavaHelper : public PlanetJavaHelper {
		public:
			SunJavaHelper(JNIEnv* env);
			~SunJavaHelper();
	};
}
