#pragma once
#include <jni.h>
#include <AstronomicalBodyJavaHelper.h>

namespace JavaUtils {
	class MoonJavaHelper : public AstronomicalBodyJavaHelper {
		public:
			MoonJavaHelper(JNIEnv* env);
			~MoonJavaHelper();
	};
}
