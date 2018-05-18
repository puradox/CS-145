#include "avr.h"
#include "lcd.h"

#include <avr/io.h>

#define DDR DDRB
#define PORT PORTB
#define RS_PIN 0
#define RW_PIN 1
#define EN_PIN 2

#define COPY_BIT(src, src_i, dest, dest_i) GET_BIT(src, src_i) ? SET_BIT(dest, dest_i) : CLR_BIT(dest, dest_i)

static inline void
set_data(unsigned char x)
{
    // Write x to certain B and D ports
    COPY_BIT(x, 0, PORTB, 3);
    COPY_BIT(x, 1, PORTB, 4);
    COPY_BIT(x, 2, PORTD, 0);
    COPY_BIT(x, 3, PORTD, 1);
    COPY_BIT(x, 4, PORTD, 2);
    COPY_BIT(x, 5, PORTD, 3);
    COPY_BIT(x, 6, PORTD, 6);
    COPY_BIT(x, 7, PORTD, 7);

    // Program certain B and D ports to output
	SET_BIT(DDRB, 3);
	SET_BIT(DDRB, 4);
	SET_BIT(DDRD, 0);
	SET_BIT(DDRD, 1);
	SET_BIT(DDRD, 2);
	SET_BIT(DDRD, 3);
	SET_BIT(DDRD, 6);
	SET_BIT(DDRD, 7);
}

static inline unsigned char
get_data(void)
{
	CLR_BIT(DDRB, 3);
	CLR_BIT(DDRB, 4);
	CLR_BIT(DDRD, 0);
	CLR_BIT(DDRD, 1);
	CLR_BIT(DDRD, 2);
	CLR_BIT(DDRD, 3);
	CLR_BIT(DDRD, 6);
	CLR_BIT(DDRD, 7);

    unsigned char x = 0;
    COPY_BIT(PINB, 3, x, 0);
    COPY_BIT(PINB, 4, x, 1);
    COPY_BIT(PIND, 0, x, 2);
    COPY_BIT(PIND, 1, x, 3);
    COPY_BIT(PIND, 2, x, 4);
    COPY_BIT(PIND, 3, x, 5);
    COPY_BIT(PIND, 6, x, 6);
    COPY_BIT(PIND, 7, x, 7);
    return x;
}

static inline void
sleep_700ns(void)
{
    NOP();
    NOP();
    NOP();
}

static unsigned char
input(unsigned char rs)
{
    unsigned char d;
    if (rs)
        SET_BIT(PORT, RS_PIN);
    else
        CLR_BIT(PORT, RS_PIN);
    SET_BIT(PORT, RW_PIN);
    get_data();
    SET_BIT(PORT, EN_PIN);
    sleep_700ns();
    d = get_data();
    CLR_BIT(PORT, EN_PIN);
    return d;
}

static void
output(unsigned char d, unsigned char rs)
{
    if (rs)
        SET_BIT(PORT, RS_PIN);
    else
        CLR_BIT(PORT, RS_PIN);
    CLR_BIT(PORT, RW_PIN);
    set_data(d);
    SET_BIT(PORT, EN_PIN);
    sleep_700ns();
    CLR_BIT(PORT, EN_PIN);
}

static void
write(unsigned char c, unsigned char rs)
{
    while (input(0) & 0x80)
        ;
    output(c, rs);
}

void ini_lcd(void)
{
    SET_BIT(DDR, RS_PIN);
    SET_BIT(DDR, RW_PIN);
    SET_BIT(DDR, EN_PIN);
    wait_avr(16);
    output(0x30, 0);
    wait_avr(5);
    output(0x30, 0);
    wait_avr(1);
    write(0x3c, 0);
    write(0x0c, 0);
    write(0x06, 0);
    write(0x01, 0);
}

void clr_lcd(void)
{
    write(0x01, 0);
}

void pos_lcd(unsigned char r, unsigned char c)
{
    unsigned char n = r * 40 + c;
    write(0x02, 0);
    while (n--)
    {
        write(0x14, 0);
    }
}

void put_lcd(char c)
{
    write(c, 1);
}

void puts_lcd1(const char *s)
{
    char c;
    while ((c = pgm_read_byte(s++)) != 0)
    {
        write(c, 1);
    }
}

void puts_lcd2(const char *s)
{
    char c;
    while ((c = *(s++)) != 0)
    {
        write(c, 1);
    }
}

void enable_cursor(void)
{
    write(0x0e, 0);
}

void disable_cursor(void)
{
    write(0x0c, 0);
}
