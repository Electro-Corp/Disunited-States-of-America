-- Test script
function init()
    print("inited!")
end

count = 0

moving = false

function update(gameObj)
   

    gameObj.transform.scale.x = 0.03
    gameObj.transform.scale.y = 0.03
    
    --[[if math.abs(targetX - gameObj.transform.position.x) < 10 and math.abs(targetY -gameObj.transform.position.y) < 10 then
        count = 0
        moving = false
    else
        gameObj.transform.position.x = gameObj.transform.position.x + ((targetX - gameObj.transform.position.x) / 1000)
        gameObj.transform.position.y = gameObj.transform.position.y + ((targetY - gameObj.transform.position.y) / 1000)
	    gameObj.transform.angle = 90 + (math.atan2(targetY - gameObj.transform.position.y, targetX - gameObj.transform.position.x) * (180 / 3.14))
    end]]
    --[[if targetX > windowX - 50 then
        Graphics:moveView(0.5, 0)
    end
    if targetX < 50 then
        Graphics:moveView(-0.5, 0)
    end
    if targetY > windowY - 50 then
        Graphics:moveView(0, 0.5)
    end
    if targetY < 0 then
        Graphics:moveView(0, -0.5)
    end]]


    

end
