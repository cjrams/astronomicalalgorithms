package org.astronomical.algorithms;

import java.util.Calendar;
import java.util.TimeZone;

public class Moon {
	public Moon(Calendar date, float latitude, float longitude) {
		TimeZone timeZone = TimeZone.getTimeZone("GTM");
		rise = Calendar.getInstance(timeZone);
		set = Calendar.getInstance(timeZone);
		transit = Calendar.getInstance(timeZone);
		CalcPosition(date, longitude ,latitude);
	}

	public Calendar getRise(){
		return rise;
	}

	public Calendar getSet(){
		return set;
	}

	public Calendar getTransit(){
		return transit;
	}

	private Calendar rise, set, transit;

	private native void CalcPosition(Calendar date, float longitude, float latitude);

	static {
		System.loadLibrary("astronomicalAlgorithms");
	}
}
