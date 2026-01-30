#include <vector>
#include "hospitalStudents.cpp"

// Verify every hospital and student are in a one-to-one matching with no duplicates.
bool verifyMatching(const std::vector<Hospital>& hospitals, const std::vector<Student>& students) {
    const size_t n = hospitals.size();
    if (students.size() != n || n == 0) {
        return false;
    }

    std::vector<unsigned char> studentSeen(n, 0);
    std::vector<unsigned char> hospitalSeen(n, 0);

    for (const Hospital& h : hospitals) {
        const int hosIdx = h.hosIndex;
        if (hosIdx < 0 || static_cast<size_t>(hosIdx) >= n || !h.isMatched) {
            return false;
        }

        const int stuIdx = h.matchedStudent;
        if (stuIdx < 0 || static_cast<size_t>(stuIdx) >= n || studentSeen[stuIdx]) {
            return false;
        }
        studentSeen[stuIdx] = 1;

        const Student& s = students[stuIdx];
        if (!s.isMatched || s.matchedHosIndex != hosIdx) {
            return false;
        }
    }

    for (size_t i = 0; i < n; ++i) {
        const Student& s = students[i];
        if (!s.isMatched) {
            return false;
        }

        const int hosIdx = s.matchedHosIndex;
        if (hosIdx < 0 || static_cast<size_t>(hosIdx) >= n || hospitalSeen[hosIdx]) {
            return false;
        }
        hospitalSeen[hosIdx] = 1;
    }

    return true;
}
