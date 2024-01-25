-- Test script
function init()

end

local count = 0

function update(gameObj)
    gameObj.transform.position.x = math.sin(count) * 100
    gameObj.transform.position.y = math.sin(count) * 100

    count = count + 0.01
end