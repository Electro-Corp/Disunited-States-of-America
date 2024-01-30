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
zoom = 1

-- Update
function update(gameObj)
    targetX = Graphics.mouseX
    targetY = Graphics.mouseY
    windowX = Graphics:getWindowSize().x
    windowY = Graphics:getWindowSize().y
    zoom = math.abs(zoom)
    if Graphics.mouseDown == true then
        if drag == true then
            Graphics:moveView((prevX - targetX) * zoom, (prevY - targetY) * zoom)
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
        zoom = zoom - defaultZoomDelta
    end
    if Graphics.mouseDelta < 0 then
        Graphics:zoomView(1 + defaultZoomDelta)
        zoom = zoom + defaultZoomDelta
    end
end
