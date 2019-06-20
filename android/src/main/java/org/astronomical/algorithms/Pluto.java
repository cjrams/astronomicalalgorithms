package org.astronomical.algorithms;

import java.util.Calendar;

public class Pluto extends Planet {
	public Pluto(Calendar date, float latitude, float longitude) {
		super();
		CalcPosition(date, longitude, latitude);
	}
	private native void CalcPosition(Calendar date, float longitude, float latitude);
}
