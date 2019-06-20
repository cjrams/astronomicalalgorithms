#pragma once
#include <jni.h>
#include <AstronomicalBodyJavaHelper.h>

namespace JavaUtils {
	class MarsJavaHelper : public AstronomicalBodyJavaHelper {
		public:
			MarsJavaHelper(JNIEnv* env);
			~MarsJavaHelper();
	};
}
