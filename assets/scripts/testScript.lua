-- Test script
function init()

end

local count = 0

function update(gameObj)
    -- Test transform stuff
    gameObj.transform.position.x = math.abs(math.sin(count) * 300) + 200
    gameObj.transform.position.y = math.abs(math.cos(count) * 300) + 100
    gameObj.transform.scale.x = math.abs(math.cos(count) * 2)
    gameObj.transform.scale.y = math.abs(math.sin(count) * 2)
    gameObj.transform.angle = math.abs(math.sin(count) * 360)
    

    count = count + 0.001
end