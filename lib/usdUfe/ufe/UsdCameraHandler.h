//
// Copyright 2020 Autodesk
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
#pragma once

#include <usdUfe/base/api.h>

#include <pxr/usd/usd/prim.h>

#include <ufe/cameraHandler.h>

namespace USDUFE_NS_DEF {

//! \brief Interface to create a UsdCameraHandler interface object.
class USDUFE_PUBLIC UsdCameraHandler : public Ufe::CameraHandler
{
public:
    typedef std::shared_ptr<UsdCameraHandler> Ptr;

    UsdCameraHandler() = default;

    USDUFE_DISALLOW_COPY_MOVE_AND_ASSIGNMENT(UsdCameraHandler);

    //! Create a UsdCameraHandler.
    static UsdCameraHandler::Ptr create();

    // Ufe::CameraHandler overrides
    Ufe::Camera::Ptr camera(const Ufe::SceneItem::Ptr& item) const override;

#ifdef UFE_V4_FEATURES_AVAILABLE
    Ufe::Selection find_(const Ufe::Path& path) const override;

    static Ufe::Selection
    find(const Ufe::Path& stagePath, const Ufe::Path& searchPath, const PXR_NS::UsdPrim& prim);
#endif

}; // UsdCameraHandler

} // namespace USDUFE_NS_DEF
