/*
* All or portions of this file Copyright (c) Amazon.com, Inc. or its affiliates or
* its licensors.
*
* For complete copyright and license terms please see the LICENSE at the root of this
* distribution (the "License"). All use of this software is governed by the License,
* or, if provided, by the license below or the license accompanying this file. Do not
* remove or modify any license notices. This file is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*
*/
#pragma once

#include <AzCore/Component/ComponentBus.h>
#include <AzCore/Math/Vector2.h>
#include <LyShine/UiBase.h>

class ISprite;

////////////////////////////////////////////////////////////////////////////////////////////////////
class UiButtonInterface
    : public AZ::ComponentBus
{
public: // types

    typedef std::function<void(AZ::EntityId, AZ::Vector2)> OnClickCallback;

public: // member functions

    virtual ~UiButtonInterface() {}

    //! Get the on-click callback
    virtual OnClickCallback GetOnClickCallback() = 0;

    //! Set the on-click callback
    virtual void SetOnClickCallback(OnClickCallback onClick) = 0;

    //! Get the action name
    virtual const LyShine::ActionName& GetOnClickActionName() = 0;

    //! Set the action name
    virtual void SetOnClickActionName(const LyShine::ActionName& actionName) = 0;

public: // static member data

    //! Only one component on a entity can implement the events
    static const AZ::EBusHandlerPolicy HandlerPolicy = AZ::EBusHandlerPolicy::Single;
};

typedef AZ::EBus<UiButtonInterface> UiButtonBus;

////////////////////////////////////////////////////////////////////////////////////////////////////
class UiButtonNotifications
    : public AZ::ComponentBus
{
public:

    //////////////////////////////////////////////////////////////////////////
    // EBusTraits overrides
    static const bool EnableEventQueue = true;
    //////////////////////////////////////////////////////////////////////////

public: // member functions

    virtual ~UiButtonNotifications() {}

    //! Notify listeners that the button was clicked
    virtual void OnButtonClick() {}
};

typedef AZ::EBus<UiButtonNotifications> UiButtonNotificationBus;
