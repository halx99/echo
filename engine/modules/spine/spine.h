#pragma once

#include "engine/core/scene/Node.h"
#include "engine/core/render/mesh/Mesh.h"
#include "engine/core/render/MaterialInst.h"
#include "engine/core/render/render/Renderable.h"

namespace Echo
{
	class Spine : public Node
	{
		ECHO_CLASS(Spine, Node)

		struct CanvasInfo
		{
			float		m_width;
			float		m_height;
			Vector2		m_originInPixels;
			float	    m_pixelsPerUnit;
		};

		struct Paramter
		{
			String	m_name;
			float	m_value;
			float	m_defaultValue;
			float	m_minValue;
			float	m_maxValue;
		};

		struct Part
		{
			String  m_name;
			float	m_opacities;
		};

		struct VertexFormat
		{
			Vector3		m_position;
			Vector2		m_uv;
		};
		typedef vector<VertexFormat>::type	VertexArray;
		typedef vector<Word>::type	IndiceArray;

		struct Drawable
		{
			String				m_name;
			//csmFlags			m_constantFlag;
			//csmFlags			m_dynamicFlag;
			ui32				m_textureIndex;
			ui32				m_drawOrder;
			ui32				m_renderOrder;
			float				m_opacitie;
			vector<ui32>::type	m_masks;
			VertexArray			m_vertices;
			Box					m_box;
			vector<Word>::type	m_indices;

			void reset()
			{
				m_vertices.clear();
				m_indices.clear();
			}
		};

	public:
		Spine();
		virtual ~Spine();

		// bind class methods to script
		static void bindMethods();

		// set moc
		void setMoc(const ResourcePath& res);

		// get moc
		const ResourcePath& getMoc() { return m_mocRes; }

		// set texture res path
		void setTextureRes(const ResourcePath& path);

		// get texture res
		const ResourcePath& getTextureRes() { return m_textureRes; }

		// set anim res path
		void setMotionRes(const ResourcePath& path);

		// get anim res path
		const ResourcePath& getMotionRes() const { return m_curMotionRes; }

		// set parameter value
		void setParameter(const String& name, float value);

	protected:
		// build drawable
		void buildRenderable();

		// update
		virtual void update();

		// update vertex buffer
		void updateMeshBuffer();

		// parse paramters
		void parseParams();

		// parse canvas info
		void parseCanvasInfo();

		// parse parts
		void parseParts();

		// parse drawables
		void parseDrawables();

		// build mesh data by drawables data
		void buildMeshDataByDrawables(VertexArray& oVertices, IndiceArray& oIndices);

		// get global uniforms
		virtual void* getGlobalUniformValue(const String& name);

		// clear
		void clear();
		void clearRenderable();

	private:
		ResourcePath			m_mocRes;
		ResourcePath			m_textureRes;
		ResourcePath			m_curMotionRes;
		//Live2dCubismMotion*		m_curMotion;
		MemoryReaderAlign*		m_mocMemory;
		//csmMoc*					m_moc;
		ui32					m_modelSize;
		void*					m_modelMemory;
		//csmModel*				m_model;
		ui32					m_tableSize;
		void*					m_tableMemory;
		//csmModelHashTable*		m_table;
		CanvasInfo				m_canvas;
		vector<Paramter>::type	m_params;
		vector<Part>::type		m_parts;
		vector<Drawable>::type	m_drawables;
		//MotionMap				m_motions;

		Mesh*					m_mesh;			// Geometry Data for render
		MaterialInst*			m_materialInst;	// Material Instance
		Renderable*				m_renderable;

		Matrix4					m_matWVP;
	};
}