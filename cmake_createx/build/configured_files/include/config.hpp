//  @ cmake looks for and remplaces text between @@ this text @@
//
// This helps create a file in the build directory.
// Automatically created to provide version number.

#include <cstdint>
#include <string_view>

static constexpr std::string_view project_name = "";
static constexpr std::string_view project_version = "";

// incrementing major means that
// the new version is incompatible with the last
static constexpr std::int32_t project_version_major{1};

// incrementing minor means that
// new features are available
static constexpr std::int32_t project_version_minor{0};

// incrementing patch means that
// small bugs were fixed 
static constexpr std::int32_t project_version_patch{0};
