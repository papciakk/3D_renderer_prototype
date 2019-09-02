fn exportObject obj out_name = (
	obj_to_export = snapshot obj	
	out_file = createfile out_name
	
	format ("// Object: " + obj_to_export.name + "\n") to:out_file
	
	num_vets = getNumVerts obj_to_export
	num_faces = meshop.getNumFaces obj_to_export
	
	format ("const int vertexexCount = " + num_vets as string + ";\n") to:out_file
	format ("const int faceCount = " + num_faces as string + ";\n\n") to:out_file
	
	format ("const float model[vertexexCount][3] = {\n") to:out_file

	for v = 1 to num_vets do
	(
		vertex = meshop.getVert obj_to_export v
		vx = vertex.x as string
		vy = vertex.y as string
		vz = vertex.z as string
		format ("\t{" + vx + ", " + vy + ", " + vz + "},\n") to:out_file
	)
	
	format ("};\n") to:out_file
	
		
	format ("const float vertexNormals[vertexexCount][3] = {\n") to:out_file
	
	for v = 1 to num_vets do
	(
		normal = normalize(getNormal obj_to_export v)
		nx = normal[1] as string
		ny = normal[2] as string
		nz = normal[3] as string
		format ("\t{" + nx + ", " + ny + ", " + nz + "},\n") to:out_file
	)
	
	format ("};\n") to:out_file
	
	format ("const int faces[faceCount][3] = {\n") to:out_file
	
	for f = 1 to num_faces do
	(
		face = getFace obj_to_export f
		f0 = ((face[1]-1) as integer) as string
		f1 = ((face[2]-1) as integer) as string
		f2 = ((face[3]-1) as integer) as string
		format ("\t{" + f0 + ", " + f1 + ", " + f2 + "},\n") to:out_file
	)
	
	format ("};\n") to:out_file
	
	flush out_file
	close out_file
	delete obj_to_export
	messagebox "File exported successfully" title:"info"
)

utility flatexp "Solid mesh exporter"
(
	global obj_exp
	
	pickbutton export "Pick object" width:250 autoDisplay:true
	
	on export picked obj do
	(
		if obj != undefined do
		(
			if (superClassOf obj == geometryClass) then
			(
				out_name = GetSaveFileName types:"C header file(*.h)|*.h"
				if out_name  != undefined then
				(
					exportObject obj out_name
				)
			)
		)
	)
)
