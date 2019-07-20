package org.astronomical.algorithms;

import android.support.test.runner.AndroidJUnit4;

import org.junit.Test;
import org.junit.runner.RunWith;

import static org.junit.Assert.*;

import java.util.Calendar;
import java.util.TimeZone;

@RunWith(AndroidJUnit4.class)
public class PlanetsTest {
    @Test
    public void marsTests() {
        TimeZone gmt = TimeZone.getTimeZone("GTM");
        Calendar calendar = Calendar.getInstance(gmt);
        calendar.set(2010, Calendar.NOVEMBER,15);
        Mars mars = new Mars(calendar,41.7859f, 2.1699f);

        Calendar riseCalendar = Calendar.getInstance(gmt);
        riseCalendar.set(2010, Calendar.NOVEMBER,15, 8, 25, 13);
        Calendar setCalendar = Calendar.getInstance(gmt);
        setCalendar.set(2010, Calendar.NOVEMBER,15, 17, 32, 56);
        Calendar transitCalendar = Calendar.getInstance(gmt);
        transitCalendar.set(2010, Calendar.NOVEMBER,15, 12, 59, 10);

        assertEquals(mars.getRise().getTimeInMillis(), riseCalendar.getTimeInMillis(), 1000);
        assertEquals(mars.getSet().getTimeInMillis(), setCalendar.getTimeInMillis(), 1000);
        assertEquals(mars.getTransit().getTimeInMillis(), transitCalendar.getTimeInMillis(), 1000);
    }

    @Test
    public void plutoTests() {
        TimeZone gmt = TimeZone.getTimeZone("GTM");
        Calendar calendar = Calendar.getInstance(gmt);
        calendar.set(2010, Calendar.NOVEMBER,15);
        Pluto pluto = new Pluto(calendar,41.7859f, 2.1699f);

        Calendar riseCalendar = Calendar.getInstance(gmt);
        riseCalendar.set(2010, Calendar.NOVEMBER,15, 9, 35, 17);
        Calendar setCalendar = Calendar.getInstance(gmt);
        setCalendar.set(2010, Calendar.NOVEMBER,15, 19, 18, 58);
        Calendar transitCalendar = Calendar.getInstance(gmt);
        transitCalendar.set(2010, Calendar.NOVEMBER,15, 14, 27, 7);

        assertEquals(pluto.getRise().getTimeInMillis(), riseCalendar.getTimeInMillis(), 1000);
        assertEquals(pluto.getSet().getTimeInMillis(), setCalendar.getTimeInMillis(), 1000);
        assertEquals(pluto.getTransit().getTimeInMillis(), transitCalendar.getTimeInMillis(), 1000);
    }
}

