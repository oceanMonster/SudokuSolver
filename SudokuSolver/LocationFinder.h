#pragma once

#include "BlockLocation.h"
#include <cassert>

class LocationFinder
{
public:
	static BlockLocation getBlockLocation(const int idx, const int jdx) {
		if (idx < 3 && jdx < 3) {
			// upper left block
			return BlockLocation::upperLeft;
		}
		else if (idx < 3 && jdx >= 3 && jdx < 6) {
			// upper middle
			return BlockLocation::upperMiddle;
		}
		else if (idx < 3 && jdx >= 6 && jdx < 9) {
			// upper right
			return BlockLocation::upperRight;
		}
		else if (idx >= 3 && idx < 6 && jdx < 3) {
			// middle left
			return BlockLocation::middleLeft;
		}
		else if (idx >= 3 && idx < 6 && jdx >= 3 && jdx < 6) {
			// middle middle
			return BlockLocation::middleMiddle;
		}
		else if (idx >= 3 && idx < 6 && jdx >= 6 && jdx < 9) {
			// middle right
			return BlockLocation::middleRight;
		}
		else if (idx >= 6 && idx < 9 && jdx < 3) {
			// lower left
			return BlockLocation::lowerLeft;
		}
		else if (idx >= 6 && idx < 9 && jdx >= 3 && jdx < 6) {
			// lower middle
			return BlockLocation::lowerMiddle;
		}
		else if (idx >= 6 && jdx < 9 && jdx >= 6 && jdx < 9) {
			// lower right 
			return BlockLocation::lowerRight;
		}
		else {
			assert(false);
		}
	}
};

