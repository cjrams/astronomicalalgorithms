#pragma once
#include <jni.h>
#include <AstronomicalBodyJavaHelper.h>

namespace JavaUtils {
	class PlutoJavaHelper : public AstronomicalBodyJavaHelper {
		public:
			PlutoJavaHelper(JNIEnv* env);
			~PlutoJavaHelper();
	};
}
