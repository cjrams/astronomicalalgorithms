package org.astronomical.algorithms;

import java.util.Calendar;
import java.util.TimeZone;

public abstract class Planet {
	public Planet() {
		TimeZone timeZone = TimeZone.getTimeZone("GTM");
		rise = Calendar.getInstance(timeZone);
		set = Calendar.getInstance(timeZone);
		transit = Calendar.getInstance(timeZone);
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

	static {
		System.loadLibrary("astronomicalAlgorithms");
	}
}
