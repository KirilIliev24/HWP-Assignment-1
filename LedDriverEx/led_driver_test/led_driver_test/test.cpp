#include "gtest/gtest.h"

extern "C"
{
	#include <avr/io.h>
	#include"led/led_driver.h"
}

class LEDDriverTest : public ::testing::Test
{
protected:
	void SetUp()
	{
		led_create();	
	}

	void TearDown()
	{

	}
};

TEST_F(LEDDriverTest, Test_port_is_set_to_output) {
  EXPECT_EQ(0xff, DDRA);
}

TEST_F(LEDDriverTest, Test_leds_initialy_off) {
  EXPECT_EQ(0xff, PORTA);
}

TEST_F(LEDDriverTest, First_led_turn_on) {
	led_set(0, 1);
	EXPECT_EQ(0xfe, PORTA);
}

TEST_F(LEDDriverTest, Turn_on_invalid_led) {
	led_set(9, 1);
	EXPECT_EQ(0xff, PORTA);
}

TEST_F(LEDDriverTest, Logical_operators) {
	set_logical_operators(1,0);
	//result of logical gates is 01110011
	// but led configuration is 10001111 - 8F /1 is off /0 is on
	EXPECT_EQ(0x8F, PORTA);
}