--[[
    CAMERA.LUA
    Controls the camera from lua
-- ]]

-- Initlize 
function init()
end

targetX = 0
targetY = 0

prevX = 0
prevY = 0


drag = false

defaultZoomDelta = 0.11


-- Update
function update(gameObj)
    targetX = Graphics.mouseX
    targetY = Graphics.mouseY
    windowX = Graphics:getWindowSize().x
    windowY = Graphics:getWindowSize().y
    if Graphics.mouseDown == true then
        if drag == true then
            Graphics:moveView((prevX - targetX), (prevY - targetY))
        else
            drag = true
        end
        prevX = targetX
        prevY = targetY
    else
        prevX = 0
        prevY = 0
        drag = false
    end

    if Graphics.mouseDelta > 0 then
        Graphics:zoomView(1 - defaultZoomDelta)
    end
    if Graphics.mouseDelta < 0 then
        Graphics:zoomView(1 + defaultZoomDelta)
    end
end
