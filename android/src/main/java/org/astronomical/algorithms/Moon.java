package org.astronomical.algorithms;

import android.util.Log;

import java.util.Calendar;
import java.util.TimeZone;

public class Moon {
	private final String TAG = "AstronomicalAlgorithms";

	public Moon(Calendar date, float latitude, float longitude) {
		TimeZone timeZone = TimeZone.getTimeZone("GTM");
		moonRise = Calendar.getInstance(timeZone);
		moonSet = Calendar.getInstance(timeZone);
		moonTransit = Calendar.getInstance(timeZone);
		Log.d(TAG, "Date: " + date.toString());
		Log.d(TAG, "InitialMoonRise: " + getMoonRise().toString());
		CalcMoonPosition(date, longitude ,latitude);
		Log.d(TAG, "MoonRise: " + getMoonRise().toString());
		Log.d(TAG, "MoonTransit: " + getMoonTransit().toString());
		Log.d(TAG, "MoonSet: " + getMoonSet().toString());
	}

	public Calendar getMoonRise(){
		return moonRise;
	}

	public Calendar getMoonSet(){
		return moonSet;
	}

	public Calendar getMoonTransit(){
		return moonTransit;
	}

	private Calendar moonRise, moonSet, moonTransit;
	private native void CalcMoonPosition(Calendar date, float longitude, float latitude);

	static {
		System.loadLibrary("astronomicalAlgorithms");
	}

}
