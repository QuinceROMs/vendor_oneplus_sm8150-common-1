#include <sys/types.h>
#include <string>

#include <binder/IBinder.h>
#include <utils/StrongPointer.h>

namespace android {

// Android 17 inserted a uid_t ownerUid argument into
// SurfaceComposerClient::createVirtualDisplay. Re-emit the prior signature for
// the prebuilt WFD blobs and forward to the current one with the default uid.
class SurfaceComposerClient {
  public:
    static sp<IBinder> createVirtualDisplay(const std::string& displayName, bool isSecure,
                                            bool optimizeForPower, const std::string& uniqueId,
                                            uid_t ownerUid, float requestedRefreshRate);
    static sp<IBinder> createVirtualDisplay(const std::string& displayName, bool isSecure,
                                            bool optimizeForPower, const std::string& uniqueId,
                                            float requestedRefreshRate);
};

sp<IBinder> SurfaceComposerClient::createVirtualDisplay(const std::string& displayName, bool isSecure,
                                                        bool optimizeForPower,
                                                        const std::string& uniqueId,
                                                        float requestedRefreshRate) {
    return createVirtualDisplay(displayName, isSecure, optimizeForPower, uniqueId,
                                static_cast<uid_t>(-1) /* gui::Uid::INVALID */, requestedRefreshRate);
}

}  // namespace android
