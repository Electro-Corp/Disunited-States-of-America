# Tool to convert GeoJSON to Mosaic format
import geojson
import json
import sys
import os, shutil
import random

print("==================================")
print("GeoJSON to mosiacCounty converter")
print("==================================")

folder = 'counties'
for filename in os.listdir(folder):
    file_path = os.path.join(folder, filename)
    try:
        if os.path.isfile(file_path) or os.path.islink(file_path):
            os.unlink(file_path)
        elif os.path.isdir(file_path):
            shutil.rmtree(file_path)
    except Exception as e:
        print('Failed to delete %s. Reason: %s' % (file_path, e))


try:
    filename = sys.argv[1]
    print(f"Reading GeoJSON file {filename}")
except:
    print("All args not provided!") 
    exit(-1)

empty = "                                                             "
print("Opening...")
file = open(filename, "r")
geo = geojson.load(file)
length = len(geo["features"])
done = 0
empty = 0
count = 0
for feature in geo["features"]:
    if feature["geometry"] is not None:
        rando = random.randrange(0, 300)
        conStr = feature["properties"]["NAME"] + str(done) +".mosaicCounty"
        file = open(f"counties/{conStr}", "w")
        #print(f"Generate {conStr}", end="\r", flush=True)
        print(f"Percent Complete: {int((done / length) * 100)} | Rewrote = {count} | Errors: {empty} | Current: {conStr}", end="\r", flush=True)

        pointData = feature["geometry"]["coordinates"]  
        
        points = []

        while True:
            if type(pointData[0][0]) is list:
                count += 1
                pointData = pointData[0]
            else:
                break

        """ 
        xS = []
        yS = []
        for point in pointData:
            xS.append(point[0])
            yS.append(point[1])
        
        maxX = max(xS)
        minX = min(xS)
        maxY = max(yS)
        minY = min(yS)

        for point in pointData:
            point[0] = (point[0]- minX) / (maxX - minX)
            point[1] = (point[1]- minY) / (maxY - minY)
        """

        county = {
            "NAME" : feature["properties"]["NAME"],
            "POINTS" : pointData,
            "ID" : done,
            "STATEID" : int(feature["properties"]["STATEFP"])
        }

        file.writelines(str(json.dumps(county)))
    else:   
        empty += 1
        print(feature["properties"]["NAME"] + " is empty!")
        print("")
    done += 1
print(f"Percent Complete: {int((done / length) * 100)}")
print(f"Total: {done}")
print("\nEmpty: " + str(empty))