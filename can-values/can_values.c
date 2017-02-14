void initializ_keys() {

	can_signal_create("calSwitch", "Calibration Switch Position", "None");

	can_signal_create("rm1", "Run Mode", "");

	can_signal_create("mat", "Manifold Temperature", "degC");

	can_signal_create("lam1", "Fuel Air Ratio (Lambda)", "lambda");

	can_signal_create("egt1", "Exhaust Gas Temperature", "degC");

	can_signal_create("vbat", "Battery Voltage", "V");

	can_signal_create("gear", "Gear Location", "");

	can_signal_create("eot", "Engine Oil Temperature", "degC");

	can_signal_create("tcSwitch", "Traction Control Switch Position", "None");

	can_signal_create("rpm", "RPM", "rpm");

	can_signal_create("ect1", "Engine Coolant Temperature", "degC");

}

void set_key_value(int can_id, int can_data) {

	int value;

	switch (can_id) {

	case 0x614:


			//value = CAN_PARSE_UINT16(can_data, 0);


			can_signal_set_value("gear", value);


		break;

	case 0x615:


			value = CAN_PARSE_UINT16(can_data, 0);

				value = value / 10;


			can_signal_set_value("mat", value);


			value = CAN_PARSE_UINT16(can_data, 0);


			can_signal_set_value("rm1", value);


		break;

	case 0x610:


			value = CAN_PARSE_UINT16(can_data, 0);

				value = value + 1;


			can_signal_set_value("calSwitch", value);


			value = CAN_PARSE_UINT16(can_data, 0);

				value = value + 1;


			can_signal_set_value("tcSwitch", value);


		break;

	case 0x609:


			value = CAN_PARSE_UINT16(can_data, 0);

				value = value / 10;


			can_signal_set_value("eot", value);


		break;

	case 0x603:


			value = CAN_PARSE_UINT16(can_data, 0);

				value = value / 1000;


			can_signal_set_value("lam1", value);


		break;

	case 0x600:


			value = CAN_PARSE_UINT16(can_data, 0);


			can_signal_set_value("rpm", value);


			value = CAN_PARSE_UINT16(can_data, 0);

				value = value / 1000;


			can_signal_set_value("vbat", value);


		break;

	case 0x605:


			value = CAN_PARSE_UINT16(can_data, 0);

				value = value / 10;


			can_signal_set_value("ect1", value);


			value = CAN_PARSE_UINT16(can_data, 0);

				value = value / 10;


			can_signal_set_value("egt1", value);


		break;

	}
}
