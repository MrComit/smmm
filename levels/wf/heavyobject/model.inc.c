Lights1 heavyobject_MetalCube_001_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFE, 0xFE, 0xFE, 0x28, 0x28, 0x28);

Gfx heavyobject_metal_ci4_aligner[] = {gsSPEndDisplayList()};
u8 heavyobject_metal_ci4[] = {
	0x01, 0x20, 0x20, 0x30, 0x40, 0x00, 0x33, 0x03, 
	0x33, 0x56, 0x35, 0x53, 0x33, 0x73, 0x35, 0x33, 
	0x53, 0x73, 0x53, 0x33, 0x77, 0x33, 0x33, 0x53, 
	0x33, 0x33, 0x53, 0x70, 0x87, 0x00, 0x02, 0x22, 
	0x42, 0x24, 0x73, 0x33, 0x44, 0x02, 0x33, 0x35, 
	0x55, 0x65, 0x55, 0x63, 0x53, 0x37, 0x33, 0x33, 
	0x77, 0x05, 0x38, 0x33, 0x73, 0x07, 0x07, 0x73, 
	0x73, 0x77, 0x33, 0x35, 0x08, 0x70, 0x00, 0x00, 
	0x02, 0x20, 0x30, 0x37, 0x00, 0x04, 0x33, 0x35, 
	0x65, 0x53, 0x66, 0x66, 0x53, 0x33, 0x33, 0x50, 
	0x00, 0x70, 0x33, 0x33, 0x77, 0x07, 0x20, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x20, 0x38, 0x37, 0x00, 
	0x02, 0x07, 0x00, 0x30, 0x20, 0x00, 0x33, 0x33, 
	0x55, 0x66, 0x66, 0x65, 0x33, 0x53, 0x53, 0x37, 
	0x30, 0x03, 0x73, 0x00, 0x37, 0x07, 0x20, 0x00, 
	0x04, 0x00, 0x00, 0x02, 0x40, 0x40, 0x00, 0x00, 
	0x24, 0x00, 0x00, 0x73, 0x03, 0x70, 0x37, 0x05, 
	0x66, 0x66, 0x66, 0x66, 0x55, 0x55, 0x55, 0x50, 
	0x30, 0x37, 0x37, 0x33, 0x70, 0x70, 0x00, 0x92, 
	0x24, 0x24, 0x00, 0x00, 0x00, 0x77, 0x80, 0x00, 
	0x02, 0x07, 0x00, 0x37, 0x33, 0x30, 0x57, 0x73, 
	0x66, 0xa6, 0x66, 0x66, 0x65, 0x65, 0x33, 0x57, 
	0x37, 0x78, 0x73, 0x37, 0x03, 0x87, 0x04, 0x24, 
	0x24, 0x20, 0x20, 0x00, 0x00, 0x07, 0x30, 0x00, 
	0x29, 0x40, 0x00, 0x03, 0x07, 0x04, 0x00, 0x73, 
	0x5a, 0x66, 0x66, 0x66, 0x66, 0x55, 0x35, 0x65, 
	0x30, 0x77, 0x33, 0x33, 0x07, 0x77, 0x20, 0x20, 
	0x44, 0x22, 0x00, 0x00, 0x00, 0x03, 0x37, 0x80, 
	0x22, 0x00, 0x04, 0x07, 0x00, 0x2b, 0x03, 0x33, 
	0x33, 0x6a, 0x66, 0x66, 0x66, 0x66, 0xac, 0xcc, 
	0x32, 0x07, 0x33, 0x33, 0x70, 0x00, 0x22, 0x20, 
	0x22, 0x00, 0x07, 0x00, 0x78, 0x03, 0x37, 0x00, 
	0x00, 0x77, 0x00, 0x00, 0x00, 0x21, 0x03, 0x53, 
	0x33, 0x36, 0x66, 0xc6, 0x66, 0x66, 0xcc, 0xcc, 
	0x52, 0x03, 0x03, 0x07, 0x03, 0x77, 0x24, 0x22, 
	0x42, 0x20, 0x73, 0x33, 0x70, 0x73, 0x37, 0x30, 
	0x00, 0x73, 0x00, 0x00, 0x08, 0x09, 0x05, 0xaa, 
	0xa6, 0x6a, 0xca, 0xca, 0x66, 0x65, 0xcc, 0xcc, 
	0x32, 0x00, 0x33, 0x73, 0x33, 0x70, 0x40, 0x40, 
	0x02, 0x07, 0x33, 0x33, 0x33, 0x33, 0x33, 0x00, 
	0x00, 0x03, 0x04, 0x03, 0x07, 0x01, 0x05, 0xcc, 
	0xcc, 0xac, 0xcc, 0xc6, 0x6a, 0x66, 0x6c, 0xcc, 
	0x72, 0x00, 0x03, 0x73, 0x37, 0x37, 0x04, 0x44, 
	0x24, 0x08, 0x33, 0x33, 0x73, 0x33, 0x30, 0x80, 
	0x07, 0x03, 0x30, 0x07, 0x08, 0x01, 0x05, 0xcc, 
	0xcc, 0x6c, 0xcc, 0xca, 0x65, 0x65, 0x6a, 0xcc, 
	0x72, 0x03, 0x03, 0x73, 0x33, 0x33, 0x70, 0x04, 
	0x00, 0x00, 0x03, 0x35, 0x00, 0x07, 0x33, 0x33, 
	0x00, 0x03, 0x30, 0x33, 0x33, 0x09, 0x05, 0xac, 
	0xaa, 0x5a, 0xcc, 0xcc, 0x65, 0x65, 0x55, 0x66, 
	0x04, 0x07, 0x33, 0x33, 0x33, 0x33, 0x73, 0x00, 
	0x70, 0x00, 0x40, 0x33, 0x00, 0x00, 0x33, 0x33, 
	0x30, 0x77, 0x30, 0x33, 0x33, 0x79, 0x75, 0xa6, 
	0x56, 0x56, 0xca, 0x66, 0x55, 0x53, 0x33, 0x35, 
	0x42, 0x00, 0x87, 0x83, 0x33, 0x35, 0x35, 0x33, 
	0x33, 0x30, 0x22, 0x77, 0x20, 0x83, 0x33, 0x55, 
	0x00, 0x03, 0x37, 0x88, 0x33, 0x09, 0x76, 0x66, 
	0x56, 0x66, 0xaa, 0x65, 0x53, 0x53, 0x33, 0x55, 
	0x00, 0x07, 0x77, 0x30, 0x35, 0x66, 0x66, 0x55, 
	0x66, 0xa6, 0x70, 0x22, 0x07, 0x83, 0x55, 0x33, 
	0x33, 0x73, 0x70, 0x08, 0x33, 0x02, 0x06, 0x65, 
	0x56, 0xaa, 0xa6, 0x63, 0x65, 0x53, 0x33, 0x85, 
	0x02, 0x77, 0x30, 0x00, 0x73, 0x6a, 0x66, 0x6a, 
	0xac, 0xcc, 0x58, 0x00, 0x00, 0x08, 0x33, 0x35, 
	0x30, 0x03, 0x30, 0x00, 0x33, 0x02, 0x05, 0x00, 
	0x35, 0x55, 0x67, 0x03, 0x53, 0x37, 0x21, 0x05, 
	0x00, 0x03, 0x00, 0x00, 0x03, 0x66, 0x66, 0x6a, 
	0xca, 0xca, 0x66, 0x00, 0x00, 0x03, 0x38, 0x37, 
	0x33, 0x37, 0x30, 0x03, 0x77, 0x72, 0x08, 0xb9, 
	0x88, 0x73, 0x39, 0xb4, 0x33, 0x87, 0x21, 0x03, 
	0x22, 0x30, 0x00, 0x00, 0x73, 0x66, 0x66, 0x66, 
	0x65, 0x55, 0x6a, 0x50, 0x42, 0x07, 0x33, 0x83, 
	0x30, 0x07, 0x80, 0x00, 0x03, 0x29, 0x23, 0x00, 
	0x70, 0x30, 0x04, 0x20, 0x33, 0x30, 0x04, 0x00, 
	0x24, 0x04, 0x24, 0x44, 0x03, 0x56, 0x66, 0x65, 
	0x53, 0x33, 0x55, 0x58, 0x2d, 0x10, 0x00, 0x00, 
	0x24, 0x00, 0x22, 0x42, 0x00, 0x21, 0x90, 0x43, 
	0x73, 0x00, 0x44, 0x00, 0x77, 0x00, 0x00, 0x49, 
	0x11, 0xbb, 0xbb, 0x22, 0x73, 0x55, 0x65, 0x53, 
	0x35, 0x33, 0x33, 0x33, 0x01, 0x00, 0x2b, 0xb1, 
	0x29, 0x22, 0x11, 0x11, 0x12, 0x1b, 0x20, 0x00, 
	0x07, 0x02, 0x02, 0x44, 0x08, 0x74, 0x22, 0x29, 
	0xb1, 0x1b, 0xbd, 0x13, 0x33, 0x36, 0x63, 0x53, 
	0x73, 0x30, 0x73, 0x30, 0x70, 0x33, 0x0b, 0x19, 
	0x42, 0x22, 0x12, 0x99, 0x92, 0x9b, 0xb1, 0x22, 
	0x29, 0x99, 0x99, 0x22, 0x20, 0x77, 0x00, 0x02, 
	0x91, 0x99, 0x9b, 0x25, 0x53, 0x53, 0x55, 0x63, 
	0x33, 0x80, 0x77, 0x70, 0x30, 0x75, 0x32, 0x40, 
	0x22, 0x29, 0x91, 0xbb, 0x20, 0x29, 0x92, 0x22, 
	0x42, 0x22, 0x22, 0x24, 0x00, 0x03, 0x33, 0x72, 
	0x00, 0x00, 0x2b, 0x46, 0x50, 0x03, 0x56, 0xa6, 
	0x33, 0x80, 0x33, 0x77, 0x34, 0x73, 0x01, 0x27, 
	0x29, 0x19, 0x99, 0xbb, 0x24, 0x09, 0x22, 0x22, 
	0x22, 0x92, 0x22, 0x24, 0x00, 0x00, 0x70, 0x30, 
	0x00, 0x04, 0x9b, 0x47, 0x39, 0xb7, 0x56, 0x65, 
	0x33, 0x00, 0x07, 0x77, 0x07, 0x00, 0x1b, 0xb2, 
	0x02, 0x19, 0x11, 0x92, 0x22, 0x29, 0x22, 0x02, 
	0x22, 0x22, 0x22, 0x22, 0x02, 0x20, 0x9b, 0x24, 
	0x40, 0x00, 0x21, 0x00, 0x04, 0x07, 0x33, 0x33, 
	0x30, 0x00, 0x00, 0x00, 0x00, 0x04, 0xbb, 0x12, 
	0x29, 0x19, 0x11, 0x92, 0x22, 0x21, 0x20, 0x04, 
	0x22, 0x92, 0x24, 0x40, 0x02, 0x22, 0x1b, 0x42, 
	0x20, 0x00, 0x21, 0x07, 0x00, 0x33, 0x07, 0x87, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x79, 0xbb, 0x99, 
	0x11, 0x99, 0x11, 0x22, 0x22, 0x9b, 0x23, 0x34, 
	0x29, 0x21, 0x22, 0x07, 0x04, 0x22, 0x20, 0x99, 
	0x22, 0x00, 0x21, 0x03, 0x80, 0x33, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x1b, 0x09, 0xbb, 0x24, 
	0x11, 0x11, 0x1b, 0x29, 0x22, 0x1b, 0xb2, 0x30, 
	0x22, 0x19, 0x92, 0x22, 0x22, 0x91, 0x1b, 0xbb, 
	0x12, 0x02, 0x91, 0x07, 0x30, 0x33, 0x80, 0x00, 
	0x00, 0x00, 0x00, 0x04, 0xbb, 0x42, 0xbb, 0x99, 
	0x11, 0x11, 0x1b, 0x11, 0x99, 0x29, 0x11, 0x22, 
	0x22, 0x12, 0x99, 0x11, 0x11, 0xbb, 0xb1, 0xbb, 
	0x12, 0x42, 0x1b, 0x17, 0x30, 0x33, 0x00, 0x40, 
	0x00, 0x00, 0x00, 0x00, 0x04, 0x02, 0xbb, 0x22, 
	0x11, 0x11, 0x1b, 0x11, 0x12, 0x22, 0x22, 0x24, 
	0x42, 0x12, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 
	0x92, 0x21, 0x1b, 0xb4, 0x73, 0x34, 0x40, 0x42, 
	0x40, 0x00, 0x07, 0x00, 0x00, 0x30, 0x11, 0x22, 
	0x99, 0x11, 0x11, 0x11, 0x92, 0x22, 0x92, 0x24, 
	0x02, 0x29, 0x22, 0x42, 0x22, 0x22, 0x22, 0x29, 
	0x11, 0x91, 0x1b, 0xb2, 0x38, 0x0b, 0x10, 0x42, 
	0x00, 0x00, 0x73, 0x37, 0x78, 0x00, 0x19, 0x22, 
	0x92, 0x22, 0x11, 0x11, 0x92, 0x22, 0x24, 0x40, 
	0x40, 0x24, 0x00, 0x22, 0x22, 0x22, 0x22, 0x29, 
	0x11, 0x19, 0x1b, 0xb1, 0x07, 0x74, 0x20, 0x20, 
	0x40, 0x03, 0x83, 0x38, 0x77, 0x04, 0x19, 0x99, 
	0x22, 0x29, 0x91, 0x11, 0x22, 0x22, 0x40, 0x20, 
	0x00, 0x40, 0x04, 0x00, 0x22, 0x20, 0x41, 0x22, 
	0x91, 0xbb, 0x1b, 0x11, 0x00, 0x07, 0x70, 0x04, 
	0x00, 0x37, 0x33, 0x38, 0x02, 0x00, 0x92, 0x44, 
	0x22, 0x22, 0x21, 0x91, 0x12, 0x20, 0x00, 0x20, 
	0x04, 0x00, 0x00, 0x00, 0x42, 0x22, 0x22, 0x29, 
	0x91, 0xbb, 0x11, 0x21, 0x40, 0x07, 0x37, 0x00, 
	0x00, 0x00, 0x07, 0x33, 0xbb, 0x07, 0x92, 0x22, 
	0x22, 0x22, 0x29, 0x99, 0x22, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x22, 0x22, 0x22, 0x22, 
	0x99, 0x99, 0x92, 0x11, 0x00, 0x02, 0x03, 0x70, 
	0x00, 0x00, 0x20, 0x33, 0x22, 0x37, 0x22, 0x22, 
	0x24, 0x22, 0x12, 0x22, 0x00, 0x40, 0x04, 0x02, 
	0x00, 0x00, 0x00, 0x02, 0x42, 0x22, 0x22, 0x22, 
	0x92, 0x22, 0x40, 0x49, 0x07, 0x4b, 0x93, 0x80, 
	0x00, 0x00, 0x00, 0x73, 0x33, 0x33, 0x02, 0x22, 
	0x22, 0x22, 0x22, 0x22, 0x00, 0x07, 0x00, 0x00, 
	0x73, 0x80, 0x70, 0x00, 0x22, 0x24, 0x22, 0x22, 
	0x29, 0x20, 0x33, 0x09, 0x70, 0x02, 0x03, 0x30, 
	0x08, 0x00, 0x00, 0x73, 0x55, 0x33, 0x09, 0x24, 
	0x22, 0x92, 0x12, 0x22, 0x00, 0x03, 0x30, 0x07, 
	0x73, 0x87, 0x70, 0x00, 0x00, 0x20, 0x24, 0x22, 
	0x29, 0x20, 0x03, 0x41, 0x00, 0x00, 0x03, 0x78, 
	0x03, 0x70, 0x70, 0x35, 0x36, 0x33, 0x02, 0x20, 
	0x22, 0x22, 0x99, 0x22, 0x00, 0x07, 0x38, 0x33, 
	0x33, 0x33, 0x04, 0x44, 0x00, 0x22, 0x22, 0x99, 
	0x99, 0x12, 0x00, 0x21, 0x02, 0x22, 0x22, 0x22, 
	0x20, 0x07, 0x76, 0x65, 0x53, 0x30, 0x72, 0x20, 
	0x22, 0x24, 0x22, 0x20, 0x40, 0x08, 0x35, 0x56, 
	0x55, 0x53, 0x00, 0x40, 0x75, 0x60, 0x22, 0x22, 
	0x00, 0x07, 0x55, 0x74, 0x57, 0x29, 0x22, 0x20, 
	0x07, 0x33, 0x76, 0xac, 0xcc, 0x65, 0x32, 0x22, 
	0x22, 0x42, 0x92, 0x24, 0x20, 0x07, 0x36, 0x66, 
	0x66, 0x53, 0x07, 0x83, 0x6c, 0xa3, 0x40, 0x07, 
	0x33, 0x03, 0x65, 0x80, 0xa6, 0x33, 0x33, 0x53, 
	0x08, 0x30, 0x83, 0x6c, 0xcc, 0xcc, 0xc2, 0x22, 
	0x22, 0x44, 0x22, 0x40, 0x00, 0x07, 0x56, 0x6a, 
	0x66, 0x60, 0x70, 0x33, 0x35, 0x33, 0x02, 0x00, 
	0x33, 0x00, 0x33, 0x22, 0x66, 0x63, 0x33, 0x33, 
	0x21, 0x78, 0x35, 0x6c, 0x65, 0x6a, 0x52, 0x92, 
	0x22, 0x22, 0x20, 0x00, 0x02, 0x40, 0x56, 0xaa, 
	0xa6, 0x33, 0x00, 0x87, 0x70, 0x00, 0x42, 0x47, 
	0x37, 0x4b, 0x20, 0x29, 0x66, 0x65, 0x53, 0x33, 
	0x21, 0x03, 0x53, 0x55, 0x29, 0x03, 0x09, 0x22, 
	0x92, 0x22, 0x40, 0x00, 0x04, 0x07, 0x36, 0x66, 
	0x66, 0x33, 0x87, 0x83, 0x00, 0x40, 0x22, 0x20, 
	0x00, 0x22, 0x00, 0x22, 0x66, 0x66, 0x66, 0x55, 
	0x33, 0x55, 0x55, 0x37, 0x21, 0x03, 0x01, 0x22, 
	0x99, 0x29, 0x20, 0x20, 0x02, 0x00, 0x33, 0x66, 
	0xa6, 0x37, 0x87, 0x33, 0x00, 0x20, 0x24, 0x24, 
	0x00, 0x40, 0x00, 0x02, 0x66, 0x66, 0x66, 0x53, 
	0x33, 0x33, 0x37, 0x77, 0x00, 0x40, 0x71, 0x92, 
	0x19, 0x22, 0x20, 0x24, 0x00, 0x44, 0x05, 0x36, 
	0xa6, 0x33, 0x03, 0x30, 0x00, 0x22, 0x22, 0x22, 
	0x22, 0x00, 0x00, 0x00, 0x66, 0x66, 0x66, 0x55, 
	0x33, 0x33, 0x77, 0x00, 0x00, 0x07, 0x39, 0x29, 
	0x91, 0x12, 0x22, 0x24, 0x00, 0x40, 0x85, 0x55, 
	0x53, 0x00, 0x88, 0x80, 0x04, 0x04, 0x22, 0x22, 
	0x24, 0x20, 0x07, 0x70, 0xaa, 0xcc, 0x6a, 0x66, 
	0x53, 0x35, 0x37, 0x04, 0x44, 0x03, 0x51, 0x19, 
	0x91, 0x22, 0x22, 0x44, 0x04, 0x40, 0x86, 0x53, 
	0x00, 0x00, 0x08, 0x00, 0x22, 0x22, 0x22, 0x22, 
	0x22, 0x22, 0x07, 0x00, 0xaa, 0xa6, 0xac, 0xa6, 
	0x53, 0x83, 0x37, 0x04, 0x42, 0x27, 0x31, 0x99, 
	0x19, 0x24, 0x20, 0x04, 0x42, 0x19, 0x33, 0x37, 
	0x00, 0x9b, 0x94, 0x02, 0x22, 0x1b, 0x14, 0x92, 
	0x22, 0x1d, 0x17, 0x22, 0x6c, 0xac, 0xca, 0xaa, 
	0x65, 0x07, 0x70, 0x04, 0x42, 0x40, 0x7b, 0x11, 
	0x12, 0x22, 0x00, 0x04, 0x40, 0x12, 0x07, 0x30, 
	0x02, 0x1b, 0x92, 0x22, 0x99, 0x1b, 0x12, 0x22, 
	0x02, 0x21, 0x20, 0x22, 0x6c, 0xac, 0xa6, 0x6a, 
	0x66, 0x33, 0x80, 0x04, 0x9b, 0x20, 0x3b, 0x22, 
	0x92, 0x22, 0x07, 0x00, 0x00, 0x40, 0x70, 0x07, 
	0x00, 0x22, 0x22, 0x29, 0x11, 0x11, 0x19, 0x29, 
	0x21, 0x22, 0x00, 0x22, 0x6a, 0xaa, 0xaa, 0x66, 
	0x55, 0x33, 0x37, 0x00, 0x9b, 0x20, 0x4b, 0x20, 
	0x11, 0xb1, 0x92, 0x42, 0x22, 0x42, 0x44, 0x24, 
	0x22, 0x22, 0x21, 0x99, 0x19, 0x22, 0x91, 0x11, 
	0x99, 0x99, 0x9b, 0xbb, 0x66, 0x66, 0x66, 0x66, 
	0x35, 0x35, 0x63, 0x30, 0x02, 0x24, 0x2b, 0x20, 
	0x21, 0x19, 0x22, 0x04, 0x77, 0x02, 0x09, 0x2b, 
	0x11, 0x11, 0x91, 0x92, 0x22, 0x36, 0x50, 0x24, 
	0x04, 0x44, 0x22, 0xb9, 0x56, 0x66, 0x66, 0x55, 
	0x55, 0x35, 0x53, 0x22, 0x22, 0x20, 0x34, 0x56, 
	0x00, 0x70, 0x36, 0x66, 0x6c, 0xa6, 0xc6, 0x60, 
	0x03, 0x33, 0x33, 0x35, 0x55, 0x6c, 0x65, 0x33, 
	0x63, 0x56, 0x35, 0x65, 0x65, 0x56, 0x56, 0x65, 
	0x55, 0x53, 0x87, 0x29, 0x24, 0x00, 0x72, 0x35, 
	0x40, 0x00, 0x33, 0x55, 0x33, 0x33, 0x56, 0x83, 
	0x83, 0x33, 0x00, 0x33, 0x35, 0x56, 0x37, 0x00, 
	0x77, 0x33, 0x33, 0x35, 0x33, 0x56, 0x56, 0x65, 
	0x55, 0x65, 0x30, 0x02, 0x22, 0x76, 0x01, 0x00, 
	0x00, 0x30, 0x35, 0x53, 0x30, 0x20, 0x53, 0x00, 
	0x00, 0x03, 0x02, 0x73, 0x33, 0x33, 0x73, 0x00, 
	0x83, 0x33, 0x00, 0x00, 0x03, 0x3a, 0x66, 0x66, 
	0x66, 0x66, 0x65, 0x33, 0x91, 0x3a, 0x62, 0x20, 
	0x77, 0x80, 0x73, 0x37, 0x30, 0x00, 0x53, 0x00, 
	0x00, 0x00, 0x41, 0x00, 0x74, 0x20, 0x00, 0x20, 
	0x02, 0x42, 0x12, 0x04, 0x03, 0x56, 0x66, 0x66, 
	0xaa, 0xcc, 0xc6, 0x66, 0x67, 0x03, 0x32, 0x03, 
	0x33, 0x73, 0x33, 0x33, 0x33, 0x37, 0x67, 0x80, 
	0x70, 0x00, 0x02, 0x07, 0x02, 0xd9, 0x00, 0x40, 
	0x42, 0x21, 0xb1, 0x12, 0x40, 0x77, 0x00, 0x20, 
	0x03, 0x66, 0x53, 0x53, 0x35, 0x04, 0x00, 0x33, 
	0x33, 0x33, 0x33, 0x33, 0x70, 0x07, 0x33, 0x00, 
	0x70, 0x03, 0x09, 0x00, 0x02, 0x12, 0x40, 0x00, 
	0x02, 0x22, 0x11, 0xdb, 0x44, 0x00, 0x00, 0x02, 
	0x02, 0x20, 0x02, 0x21, 0x11, 0xbb, 0x98, 0x33, 
	0x33, 0x07, 0x33, 0x33, 0x33, 0x30, 0x53, 0x00, 
	0x07, 0x03, 0x04, 0x03, 0x37, 0x03, 0x78, 0x73, 
	0x07, 0x00, 0x42, 0x12, 0x00, 0x70, 0x03, 0x30, 
	0x0b, 0xb4, 0x00, 0x00, 0x22, 0x20, 0x73, 0x73, 
	0x63, 0x00, 0x00, 0x33, 0x33, 0x70, 0x33, 0x40, 
	0x07, 0x37, 0x73, 0x33, 0x37, 0x78, 0x07, 0x00, 
	0x00, 0x40, 0x22, 0x40, 0x00, 0x07, 0x33, 0x00, 
	0x02, 0x93, 0x83, 0x38, 0x00, 0x44, 0x00, 0x03, 
	0x30, 0x07, 0x07, 0x35, 0x50, 0x92, 0x03, 0x03, 
	0x33, 0x33, 0x33, 0x33, 0x30, 0x73, 0x07, 0x03, 
	0x33, 0x37, 0x00, 0x04, 0x00, 0x77, 0x33, 0x70, 
	0x37, 0x00, 0x30, 0x00, 0x40, 0x42, 0x09, 0x20, 
	0x02, 0x20, 0x80, 0x00, 0x02, 0x92, 0x33, 0x00, 
	0x73, 0x33, 0x33, 0x35, 0x30, 0x70, 0x70, 0x00, 
	0x08, 0x37, 0x07, 0x04, 0x40, 0x33, 0x33, 0x77, 
	0x33, 0x35, 0x53, 0x37, 0x00, 0x22, 0x02, 0x94, 
	0x22, 0x24, 0x40, 0x00, 0x04, 0x22, 0x37, 0x03, 
	0x55, 0x33, 0x35, 0x55, 0x53, 0x83, 0x33, 0x33, 
	0x37, 0x30, 0x33, 0x70, 0x00, 0x33, 0x33, 0x30, 
	0x33, 0x83, 0x38, 0x37, 0x00, 0x42, 0x22, 0x22, 
	
};

Gfx heavyobject_metal_ci4_pal_rgba16_aligner[] = {gsSPEndDisplayList()};
u8 heavyobject_metal_ci4_pal_rgba16[] = {
	0x73, 0x5b, 0x62, 0xd7, 0x6b, 0x19, 0x7b, 0x9d, 
	0x6b, 0x59, 0x7b, 0xdd, 0x83, 0xdf, 0x73, 0x9b, 
	0x7b, 0x9b, 0x63, 0x19, 0x84, 0x1f, 0x5a, 0xd7, 
	0x8c, 0x21, 0x52, 0x53, 
};

Vtx heavyobject_Body_mesh_layer_1_vtx_0[96] = {
	{{{0, 0, 33},0, {3682, 491},{0x13, 0x0, 0x7E, 0xFF}}},
	{{{-39, 19, 39},0, {4610, 906},{0x13, 0x0, 0x7E, 0xFF}}},
	{{{-39, 0, 39},0, {4610, 491},{0x13, 0x0, 0x7E, 0xFF}}},
	{{{0, 16, 33},0, {3682, 906},{0x13, 0x0, 0x7E, 0xFF}}},
	{{{-39, 0, 39},0, {4610, 491},{0x82, 0x0, 0xED, 0xFF}}},
	{{{-39, 19, 39},0, {4610, 906},{0x82, 0x0, 0xED, 0xFF}}},
	{{{-33, 16, 0},0, {5537, 906},{0x82, 0x0, 0xED, 0xFF}}},
	{{{-33, 0, 0},0, {5537, 491},{0x82, 0x0, 0xED, 0xFF}}},
	{{{0, 0, 33},0, {2032, 667},{0x0, 0x81, 0x0, 0xFF}}},
	{{{-39, 0, 39},0, {2032, -16},{0x0, 0x81, 0x0, 0xFF}}},
	{{{-33, 0, 0},0, {667, -16},{0x0, 0x81, 0x0, 0xFF}}},
	{{{0, 0, -33},0, {-16, 1349},{0x0, 0x81, 0x0, 0xFF}}},
	{{{-39, 0, -39},0, {-16, -16},{0x0, 0x81, 0x0, 0xFF}}},
	{{{33, 0, 0},0, {1349, 2032},{0x0, 0x81, 0x0, 0xFF}}},
	{{{39, 0, -39},0, {-16, 2032},{0x0, 0x81, 0x0, 0xFF}}},
	{{{39, 0, 39},0, {2032, 2032},{0x0, 0x81, 0x0, 0xFF}}},
	{{{0, 61, 33},0, {399, 906},{0x13, 0x0, 0x7E, 0xFF}}},
	{{{0, 77, 33},0, {-16, 906},{0x13, 0x0, 0x7E, 0xFF}}},
	{{{-39, 77, 39},0, {-16, 1833},{0x13, 0x0, 0x7E, 0xFF}}},
	{{{-39, 58, 39},0, {399, 1833},{0x13, 0x0, 0x7E, 0xFF}}},
	{{{-39, 58, 39},0, {399, 1833},{0x82, 0x0, 0xED, 0xFF}}},
	{{{-39, 77, 39},0, {-16, 1833},{0x82, 0x0, 0xED, 0xFF}}},
	{{{-33, 77, 0},0, {-16, 2760},{0x82, 0x0, 0xED, 0xFF}}},
	{{{-33, 61, 0},0, {399, 2760},{0x82, 0x0, 0xED, 0xFF}}},
	{{{-33, 77, 0},0, {667, -16},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-39, 77, 39},0, {-16, -16},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{0, 77, 33},0, {-16, 1349},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{33, 77, 0},0, {1349, 2032},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{39, 77, 39},0, {-16, 2032},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{0, 77, -33},0, {2032, 667},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{39, 77, -39},0, {2032, 2032},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-39, 77, -39},0, {2032, -16},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-33, 0, 0},0, {-550, 491},{0x82, 0x0, 0x13, 0xFF}}},
	{{{-39, 19, -39},0, {377, 906},{0x82, 0x0, 0x13, 0xFF}}},
	{{{-39, 0, -39},0, {377, 491},{0x82, 0x0, 0x13, 0xFF}}},
	{{{-33, 16, 0},0, {-550, 906},{0x82, 0x0, 0x13, 0xFF}}},
	{{{-39, 0, -39},0, {-1671, 491},{0x13, 0x0, 0x82, 0xFF}}},
	{{{-39, 19, -39},0, {-1671, 906},{0x13, 0x0, 0x82, 0xFF}}},
	{{{0, 16, -33},0, {-744, 906},{0x13, 0x0, 0x82, 0xFF}}},
	{{{0, 0, -33},0, {-744, 491},{0x13, 0x0, 0x82, 0xFF}}},
	{{{-33, 61, 0},0, {399, 1634},{0x82, 0x0, 0x13, 0xFF}}},
	{{{-33, 77, 0},0, {-16, 1634},{0x82, 0x0, 0x13, 0xFF}}},
	{{{-39, 77, -39},0, {-16, 2562},{0x82, 0x0, 0x13, 0xFF}}},
	{{{-39, 58, -39},0, {399, 2562},{0x82, 0x0, 0x13, 0xFF}}},
	{{{-39, 58, -39},0, {399, 2562},{0x13, 0x0, 0x82, 0xFF}}},
	{{{-39, 77, -39},0, {-16, 2562},{0x13, 0x0, 0x82, 0xFF}}},
	{{{0, 77, -33},0, {-16, 3489},{0x13, 0x0, 0x82, 0xFF}}},
	{{{0, 61, -33},0, {399, 3489},{0x13, 0x0, 0x82, 0xFF}}},
	{{{33, 0, 0},0, {906, 491},{0x7E, 0x0, 0xED, 0xFF}}},
	{{{39, 19, 39},0, {1833, 906},{0x7E, 0x0, 0xED, 0xFF}}},
	{{{39, 0, 39},0, {1833, 491},{0x7E, 0x0, 0xED, 0xFF}}},
	{{{33, 16, 0},0, {906, 906},{0x7E, 0x0, 0xED, 0xFF}}},
	{{{39, 0, 39},0, {1833, 491},{0xED, 0x0, 0x7E, 0xFF}}},
	{{{39, 19, 39},0, {1833, 906},{0xED, 0x0, 0x7E, 0xFF}}},
	{{{0, 16, 33},0, {2760, 906},{0xED, 0x0, 0x7E, 0xFF}}},
	{{{0, 0, 33},0, {2760, 491},{0xED, 0x0, 0x7E, 0xFF}}},
	{{{33, 61, 0},0, {399, -1870},{0x7E, 0x0, 0xED, 0xFF}}},
	{{{33, 77, 0},0, {-16, -1870},{0x7E, 0x0, 0xED, 0xFF}}},
	{{{39, 77, 39},0, {-16, -943},{0x7E, 0x0, 0xED, 0xFF}}},
	{{{39, 58, 39},0, {399, -943},{0x7E, 0x0, 0xED, 0xFF}}},
	{{{39, 58, 39},0, {399, -943},{0xED, 0x0, 0x7E, 0xFF}}},
	{{{39, 77, 39},0, {-16, -943},{0xED, 0x0, 0x7E, 0xFF}}},
	{{{0, 77, 33},0, {-16, -16},{0xED, 0x0, 0x7E, 0xFF}}},
	{{{0, 61, 33},0, {399, -16},{0xED, 0x0, 0x7E, 0xFF}}},
	{{{0, 0, -33},0, {-1870, 491},{0xED, 0x0, 0x82, 0xFF}}},
	{{{39, 19, -39},0, {-943, 906},{0xED, 0x0, 0x82, 0xFF}}},
	{{{39, 0, -39},0, {-943, 491},{0xED, 0x0, 0x82, 0xFF}}},
	{{{0, 16, -33},0, {-1870, 906},{0xED, 0x0, 0x82, 0xFF}}},
	{{{39, 0, -39},0, {-943, 491},{0x7E, 0x0, 0x13, 0xFF}}},
	{{{39, 19, -39},0, {-943, 906},{0x7E, 0x0, 0x13, 0xFF}}},
	{{{33, 16, 0},0, {-16, 906},{0x7E, 0x0, 0x13, 0xFF}}},
	{{{33, 0, 0},0, {-16, 491},{0x7E, 0x0, 0x13, 0xFF}}},
	{{{0, 61, -33},0, {399, -4646},{0xED, 0x0, 0x82, 0xFF}}},
	{{{0, 77, -33},0, {-16, -4646},{0xED, 0x0, 0x82, 0xFF}}},
	{{{39, 77, -39},0, {-16, -3719},{0xED, 0x0, 0x82, 0xFF}}},
	{{{39, 58, -39},0, {399, -3719},{0xED, 0x0, 0x82, 0xFF}}},
	{{{39, 58, -39},0, {399, -3719},{0x7E, 0x0, 0x13, 0xFF}}},
	{{{39, 77, -39},0, {-16, -3719},{0x7E, 0x0, 0x13, 0xFF}}},
	{{{33, 77, 0},0, {-16, -2792},{0x7E, 0x0, 0x13, 0xFF}}},
	{{{33, 61, 0},0, {399, -2792},{0x7E, 0x0, 0x13, 0xFF}}},
	{{{-33, 16, 0},0, {1347, 2024},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-39, 19, 39},0, {2032, 2032},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{0, 16, 33},0, {2024, 669},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{33, 16, 0},0, {669, -8},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{39, 19, 39},0, {2032, -16},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{0, 16, -33},0, {-8, 1347},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{39, 19, -39},0, {-16, -16},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-39, 19, -39},0, {-16, 2032},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{0, 61, 33},0, {1347, 2024},{0x0, 0x81, 0x0, 0xFF}}},
	{{{-39, 58, 39},0, {2032, 2032},{0x0, 0x81, 0x0, 0xFF}}},
	{{{-33, 61, 0},0, {2024, 669},{0x0, 0x81, 0x0, 0xFF}}},
	{{{0, 61, -33},0, {669, -8},{0x0, 0x81, 0x0, 0xFF}}},
	{{{-39, 58, -39},0, {2032, -16},{0x0, 0x81, 0x0, 0xFF}}},
	{{{33, 61, 0},0, {-8, 1347},{0x0, 0x81, 0x0, 0xFF}}},
	{{{39, 58, -39},0, {-16, -16},{0x0, 0x81, 0x0, 0xFF}}},
	{{{39, 58, 39},0, {-16, 2032},{0x0, 0x81, 0x0, 0xFF}}},
};

Gfx heavyobject_Body_mesh_layer_1_tri_0[] = {
	gsSPVertex(heavyobject_Body_mesh_layer_1_vtx_0 + 0, 32, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
	gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
	gsSP2Triangles(8, 9, 10, 0, 11, 8, 10, 0),
	gsSP2Triangles(10, 12, 11, 0, 11, 13, 8, 0),
	gsSP2Triangles(11, 14, 13, 0, 13, 15, 8, 0),
	gsSP2Triangles(16, 17, 18, 0, 16, 18, 19, 0),
	gsSP2Triangles(20, 21, 22, 0, 20, 22, 23, 0),
	gsSP2Triangles(24, 25, 26, 0, 24, 26, 27, 0),
	gsSP2Triangles(26, 28, 27, 0, 24, 27, 29, 0),
	gsSP2Triangles(27, 30, 29, 0, 29, 31, 24, 0),
	gsSPVertex(heavyobject_Body_mesh_layer_1_vtx_0 + 32, 32, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
	gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
	gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
	gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
	gsSP2Triangles(16, 17, 18, 0, 16, 19, 17, 0),
	gsSP2Triangles(20, 21, 22, 0, 20, 22, 23, 0),
	gsSP2Triangles(24, 25, 26, 0, 24, 26, 27, 0),
	gsSP2Triangles(28, 29, 30, 0, 28, 30, 31, 0),
	gsSPVertex(heavyobject_Body_mesh_layer_1_vtx_0 + 64, 32, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
	gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
	gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
	gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
	gsSP2Triangles(16, 17, 18, 0, 16, 18, 19, 0),
	gsSP2Triangles(18, 20, 19, 0, 19, 21, 16, 0),
	gsSP2Triangles(19, 22, 21, 0, 21, 23, 16, 0),
	gsSP2Triangles(24, 25, 26, 0, 24, 26, 27, 0),
	gsSP2Triangles(26, 28, 27, 0, 27, 29, 24, 0),
	gsSP2Triangles(27, 30, 29, 0, 29, 31, 24, 0),
	gsSPEndDisplayList(),
};

Vtx heavyobject_Sphere_mesh_layer_1_vtx_0[20] = {
	{{{0, 3, 0},0, {-337, -786},{0x0, 0x81, 0x0, 0xFF}}},
	{{{-29, 39, -10},0, {-337, 1320},{0x87, 0x0, 0xD9, 0xFF}}},
	{{{0, 39, -31},0, {1160, 696},{0x0, 0x0, 0x81, 0xFF}}},
	{{{0, 74, 0},0, {1160, 2802},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{0, 3, 0},0, {-337, 2802},{0x0, 0x81, 0x0, 0xFF}}},
	{{{-18, 39, 25},0, {1160, 1320},{0xB5, 0x0, 0x67, 0xFF}}},
	{{{-29, 39, -10},0, {-337, 696},{0x87, 0x0, 0xD9, 0xFF}}},
	{{{0, 74, 0},0, {1160, -786},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{0, 3, 0},0, {1160, -786},{0x0, 0x81, 0x0, 0xFF}}},
	{{{18, 39, 25},0, {-337, 696},{0x4B, 0x0, 0x67, 0xFF}}},
	{{{-18, 39, 25},0, {1160, 1320},{0xB5, 0x0, 0x67, 0xFF}}},
	{{{0, 74, 0},0, {-337, 2802},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{0, 3, 0},0, {1160, 2802},{0x0, 0x81, 0x0, 0xFF}}},
	{{{0, 39, -31},0, {1160, 696},{0x0, 0x0, 0x81, 0xFF}}},
	{{{29, 39, -10},0, {-337, 1320},{0x79, 0x0, 0xD9, 0xFF}}},
	{{{0, 74, 0},0, {-337, -786},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{0, 3, 0},0, {1160, -786},{0x0, 0x81, 0x0, 0xFF}}},
	{{{29, 39, -10},0, {-337, 696},{0x79, 0x0, 0xD9, 0xFF}}},
	{{{18, 39, 25},0, {1160, 1320},{0x4B, 0x0, 0x67, 0xFF}}},
	{{{0, 74, 0},0, {-337, 2802},{0x0, 0x7F, 0x0, 0xFF}}},
};

Gfx heavyobject_Sphere_mesh_layer_1_tri_0[] = {
	gsSPVertex(heavyobject_Sphere_mesh_layer_1_vtx_0 + 0, 20, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 2, 1, 0),
	gsSP2Triangles(4, 5, 6, 0, 7, 6, 5, 0),
	gsSP2Triangles(8, 9, 10, 0, 11, 10, 9, 0),
	gsSP2Triangles(12, 13, 14, 0, 15, 14, 13, 0),
	gsSP2Triangles(16, 17, 18, 0, 19, 18, 17, 0),
	gsSPEndDisplayList(),
};


Gfx mat_heavyobject_MetalCube_001[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT, TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetTextureLUT(G_TT_RGBA16),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, heavyobject_metal_ci4_pal_rgba16),
	gsDPTileSync(),
	gsDPSetTile(0, 0, 0, 256, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadSync(),
	gsDPLoadTLUTCmd(7, 13),
	gsDPPipeSync(),
	gsDPTileSync(),
	gsDPSetTextureImage(G_IM_FMT_CI, G_IM_SIZ_8b, 32, heavyobject_metal_ci4),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_8b, 4, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 6, 0, G_TX_WRAP | G_TX_NOMIRROR, 6, 0),
	gsDPLoadSync(),
	gsDPLoadTile(7, 0, 0, 126, 252),
	gsDPPipeSync(),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_4b, 4, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 6, 0, G_TX_WRAP | G_TX_NOMIRROR, 6, 0),
	gsDPSetTileSize(0, 0, 0, 252, 252),
	gsSPSetLights1(heavyobject_MetalCube_001_lights),
	gsSPEndDisplayList(),
};

Gfx mat_revert_heavyobject_MetalCube_001[] = {
	gsDPPipeSync(),
	gsDPSetTextureLUT(G_TT_NONE),
	gsSPEndDisplayList(),
};

Gfx heavyobject_Body_mesh_layer_1[] = {
	gsSPDisplayList(mat_heavyobject_MetalCube_001),
	gsSPDisplayList(heavyobject_Body_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_heavyobject_MetalCube_001),
	gsSPEndDisplayList(),
};

Gfx heavyobject_Sphere_mesh_layer_1[] = {
	gsSPDisplayList(mat_heavyobject_MetalCube_001),
	gsSPDisplayList(heavyobject_Sphere_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_heavyobject_MetalCube_001),
	gsSPEndDisplayList(),
};

Gfx heavyobject_material_revert_render_settings[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};

