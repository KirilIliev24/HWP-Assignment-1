#include "gtest/gtest.h"

extern "C"
{
	#include <avr/io.h>
	#include "switch/switch_driver.h"
}

class SwitchDriverTest : public ::testing::Test
{
protected:
	void SetUp()
	{
		init_keys();
	}

	void TearDown()
	{

	}
};

TEST_F(SwitchDriverTest, Test_port_is_set_to_input) {
	EXPECT_EQ(0xC0, DDRC);
}

TEST_F(SwitchDriverTest, Test_pull_up_resistor_up) {
	EXPECT_EQ(0xff, PORTC);
}

TEST_F(SwitchDriverTest, Test_button_is_NOT_pressed) {
	uint8_t status = PINC & _BV(0);
	EXPECT_EQ(0, status);
}