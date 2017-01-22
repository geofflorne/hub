// Includes
#include <stdio.h>

// Prototypes
void can_signal_create(string, string, string);
void can_signal_set_value(string, int);

int main() {

	// Frame 1 (0x600)
	can_signal_create("rpm", "RPM", "rpm");
	can_signal_create("vbat", "Battery Voltage", "V");

	// Frame 2 (0x601)
	// Frame 3 (0x602)

	// Frame 4 (0x603)
	can_signal_create("lam1", "Fuel Air Ratio (Lambda)", "lambda");

	// Frame 5 (0x604)

	// Frame 6 (0x605)
	can_signal_create("ect1", "Engine Coolant Temperature", "degC");
	can_signal_create("egt1", "Exhaust Gas Temperature", "degC");

	// Frame 7 (0x606)
	// Frame 8 (0x607)
	// Frame 9 (0x608)

	// Frame 10 (0x609)
	can_signal_create("eot", "Engine Oil Temperature", "degC");

	// Frame 11 (0x610)
	can_signal_create("calSwitch", "Calibration Switch Position", "None");
	can_signal_create("tcSwitch", "Traction Control Switch Position", "None");

	// Frame 12 (0x611)
	// Frame 13 (0x612)
	// Frame 14 (0x613)

	// Frame 15 (0x614)
	can_signal_create("gear", "Gear Location", "");

	// Frame 16 (0x615)
	// Frame 17 (0x616)
	// Frame 18 (0x617)

	// unknown
	can_signal_create("mat", "Manifold Temperature", "degC");
	can_signal_create("rm1", "Run Mode", "");


	switch (can_id) {

		case 0x600: // Frame 1

			value = CAN_PARSE_UINT16(can_data, 0);

			can_signal_set_value("rpm", value);
			value = CAN_PARSE_UINT16(can_data, 0);
				value = value / 1000;


			can_signal_set_value("vbat", value);
			value = CAN_PARSE_UINT16(can_data, 0);
				value = value / 10;

			break;

		case 0x603: // Frame 4

			can_signal_set_value("lam1", value);
			value = CAN_PARSE_UINT16(can_data, 0);
				value = value / 10;

			break;

		case 0x605: // Frame 6

			can_signal_set_value("ect1", value);
			value = CAN_PARSE_UINT16(can_data, 0);
				value = value / 10;

			can_signal_set_value("egt1", value);
				value = CAN_PARSE_UINT16(can_data, 0);

			break;

		case 0x609: // Frame 10

			can_signal_set_value("eot", value);
			value = CAN_PARSE_UINT16(can_data, 0);
				value = value / 10;

			break;

		case 0x610: // Frame 11

			can_signal_set_value("calSwitch", value);
			value = CAN_PARSE_UINT16(can_data, 0);
				value = value + 1;


			can_signal_set_value("tcSwitch", value);

			break;

		case 0x14:

				can_signal_set_value("gear", value);
				value = CAN_PARSE_UINT16(can_data, 0);
					value = value + 1;

	 		break;

		/*


					can_signal_set_value("mat", value);
					value = CAN_PARSE_UINT16(can_data, 0);
						value = value / 1000;


				can_signal_set_value("rm1", value);
				value = CAN_PARSE_UINT16(can_data, 0);

		*/
	}
}
