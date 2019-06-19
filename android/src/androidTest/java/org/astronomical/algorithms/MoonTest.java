package org.astronomical.algorithms;

import android.support.test.runner.AndroidJUnit4;

import org.junit.Test;
import org.junit.runner.RunWith;

import static org.junit.Assert.*;

import java.util.Calendar;
import java.util.TimeZone;

@RunWith(AndroidJUnit4.class)
public class MoonTest {
    @Test
    public void moonTests() {
        TimeZone gmt = TimeZone.getTimeZone("GTM");
        Calendar calendar = Calendar.getInstance(gmt);
        calendar.set(2010, Calendar.NOVEMBER,15);
        Moon moon = new Moon(calendar,41.7859f, 2.1699f);
        Calendar moonRiseCalendar = Calendar.getInstance(gmt);
        moonRiseCalendar.set(2010, Calendar.NOVEMBER,15, 13, 12, 20);
        Calendar moonSetCalendar = Calendar.getInstance(gmt);
        moonSetCalendar.set(2010, Calendar.NOVEMBER,15, 0, 25, 41);
        Calendar moonTransitCalendar = Calendar.getInstance(gmt);
        moonTransitCalendar.set(2010, Calendar.NOVEMBER,15, 19, 13, 54);

        assertEquals(moon.getRise().getTimeInMillis(), moonRiseCalendar.getTimeInMillis(), 1000);
        assertEquals(moon.getSet().getTimeInMillis(), moonSetCalendar.getTimeInMillis(), 1000);
        assertEquals(moon.getTransit().getTimeInMillis(), moonTransitCalendar.getTimeInMillis(), 1000);
    }
}

