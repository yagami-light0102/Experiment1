#pragma once

struct Pose {
    int x, y;
    char heading; // 'N', 'S', 'E', 'W'
};

bool operator==(const Pose& lhs, const Pose& rhs);
