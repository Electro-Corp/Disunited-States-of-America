# Tool to convert GeoJSON to Mosaic format
import geojson
import json
import sys
import os, shutil

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
for feature in geo["features"]:
    if feature["geometry"] is not None:
        conStr = feature["properties"]["NAME"] + ".mosaicCounty"
        file = open(f"counties/{conStr}", "w")
        #print(f"Generate {conStr}", end="\r", flush=True)
        print(f"Percent Complete: {int((done / length) * 100)}", end="\r", flush=True)

        pointData = feature["geometry"]["coordinates"]
        county = {
            "NAME" : feature["properties"]["NAME"],
            "POINTS" : pointData
        }

        file.writelines(str(json.dumps(county)))
    done += 1
