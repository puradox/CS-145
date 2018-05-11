#include "avr.h"
#include "lcd.h"

#include <avr/io.h>

#define DDR DDRB
#define PORT PORTB
#define RS_PIN 0
#define RW_PIN 1
#define EN_PIN 2

#define SET_BIT(p, i) ((p) |= (1 << (i)))
#define CLR_BIT(p, i) ((p) &= ~(1 << (i)))
#define GET_BIT(p, i) ((p) & (1 << (i)))
#define write(dest, dest_i, src, src_i) GET_BIT(src, src_i) ? SET_BIT(dest, dest_i) : CLR_BIT(dest, dest_i)

static inline void
set_data(unsigned char x)
{
    // TODO(Sam): Test this code

    // Write x to certain B and D ports
    write(PORTB, 3, x, 0);
    write(PORTB, 4, x, 1);
    write(PORTD, 0, x, 2);
    write(PORTD, 1, x, 3);
    write(PORTD, 2, x, 4);
    write(PORTD, 3, x, 5);
    write(PORTD, 6, x, 6);
    write(PORTD, 7, x, 7);

    // Program certain B and D ports to output
    DDRB |= _BV(DDRB3) | _BV(DDRB4);
    DDRD |= ~(_BV(DDRD4) | _BV(DDRD5)); // Skip over OC1B and OC1A
}

static inline unsigned char
get_data(void)
{
    DDRD = 0x00;
    return PIND;
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
