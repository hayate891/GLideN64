#include "Context.h"
#include "OpenGLContext/opengl_ContextImpl.h"

using namespace graphics;

Context gfxContext;

bool Context::imageTextures = false;

Context::Context() {}

Context::~Context() {
	m_impl.reset();
}


void Context::init()
{
	m_impl.reset(new opengl::ContextImpl);
	m_impl->init();
	m_fbTexFormats.reset(m_impl->getFramebufferTextureFormats());
	imageTextures = isSupported(SpecialFeatures::ImageTextures);
}

void Context::destroy()
{
	m_impl->destroy();
	m_impl.reset();
}

void Context::enable(Parameter _parameter, bool _enable)
{
	m_impl->enable(_parameter, _enable);
}

void Context::cullFace(Parameter _parameter)
{
	m_impl->cullFace(_parameter);
}

void Context::enableDepthWrite(bool _enable)
{
	m_impl->enableDepthWrite(_enable);
}

void Context::setDepthCompare(Parameter _mode)
{
	m_impl->setDepthCompare(_mode);
}

void Context::setViewport(s32 _x, s32 _y, s32 _width, s32 _height)
{
	m_impl->setViewport(_x, _y, _width, _height);
}

void Context::setScissor(s32 _x, s32 _y, s32 _width, s32 _height)
{
	m_impl->setScissor(_x, _y, _width, _height);
}

void Context::setBlending(Parameter _sfactor, Parameter _dfactor)
{
	m_impl->setBlending(_sfactor, _dfactor);
}

void Context::setBlendColor(f32 _red, f32 _green, f32 _blue, f32 _alpha)
{
	m_impl->setBlendColor(_red, _green, _blue, _alpha);
}

void Context::clearColorBuffer(f32 _red, f32 _green, f32 _blue, f32 _alpha)
{
	m_impl->clearColorBuffer(_red, _green, _blue, _alpha);
}

void Context::clearDepthBuffer()
{
	m_impl->clearDepthBuffer();
}

void Context::setPolygonOffset(f32 _factor, f32 _units)
{
	m_impl->setPolygonOffset(_factor, _units);
}

ObjectHandle Context::createTexture(Parameter _target)
{
	return m_impl->createTexture(_target);
}

void Context::deleteTexture(ObjectHandle _name)
{
	m_impl->deleteTexture(_name);
}

void Context::init2DTexture(const InitTextureParams & _params)
{
	m_impl->init2DTexture(_params);
}

void Context::update2DTexture(const UpdateTextureDataParams & _params)
{
	m_impl->update2DTexture(_params);
}

void Context::setTextureParameters(const TexParameters & _parameters)
{
	m_impl->setTextureParameters(_parameters);
}

/*---------------Framebuffer-------------*/

const FramebufferTextureFormats & Context::getFramebufferTextureFormats()
{
	return *m_fbTexFormats.get();
}

ObjectHandle Context::createFramebuffer()
{
	return m_impl->createFramebuffer();
}

void Context::deleteFramebuffer(ObjectHandle _name)
{
	m_impl->deleteFramebuffer(_name);
}

void Context::bindFramebuffer(Parameter _target, ObjectHandle _name)
{
	m_impl->bindFramebuffer(_target, _name);
}

ObjectHandle Context::createRenderbuffer()
{
	return m_impl->createRenderbuffer();
}

void Context::initRenderbuffer(const InitRenderbufferParams & _params)
{
	m_impl->initRenderbuffer(_params);
}

void Context::addFrameBufferRenderTarget(const FrameBufferRenderTarget & _params)
{
	m_impl->addFrameBufferRenderTarget(_params);
}

bool Context::blitFramebuffers(const BlitFramebuffersParams & _params)
{
	return m_impl->blitFramebuffers(_params);
}

PixelWriteBuffer * Context::createPixelWriteBuffer(size_t _sizeInBytes)
{
	return m_impl->createPixelWriteBuffer(_sizeInBytes);
}

/*---------------Shaders-------------*/

CombinerProgram * Context::createCombinerProgram(Combiner & _color, Combiner & _alpha, const CombinerKey & _key)
{
	return m_impl->createCombinerProgram(_color, _alpha, _key);
}

bool Context::saveShadersStorage(const Combiners & _combiners)
{
	return m_impl->saveShadersStorage(_combiners);
}

bool Context::loadShadersStorage(Combiners & _combiners)
{
	return m_impl->loadShadersStorage(_combiners);
}

ShaderProgram * Context::createDepthFogShader()
{
	return m_impl->createDepthFogShader();
}

ShaderProgram * Context::createMonochromeShader()
{
	return m_impl->createMonochromeShader();
}

TexDrawerShaderProgram * Context::createTexDrawerDrawShader()
{
	return m_impl->createTexDrawerDrawShader();
}

ShaderProgram * Context::createTexDrawerClearShader()
{
	return m_impl->createTexDrawerClearShader();
}

ShaderProgram * Context::createTexrectCopyShader()
{
	return m_impl->createTexrectCopyShader();
}

void Context::drawTriangles(const DrawTriangleParameters & _params)
{
	m_impl->drawTriangles(_params);
}

void Context::drawRects(const DrawRectParameters & _params)
{
	m_impl->drawRects(_params);
}

void Context::drawLine(f32 _width, SPVertex * _vertices)
{
	m_impl->drawLine(_width, _vertices);
}

void Context::drawText(const char *_pText, float _x, float _y)
{
	m_impl->drawText(_pText, _x, _y);
}

void Context::getTextSize(const char *_pText, float & _w, float & _h)
{
	m_impl->getTextSize(_pText, _w, _h);
}

f32 Context::getMaxLineWidth()
{
	return m_impl->getMaxLineWidth();
}

bool Context::isError() const
{
	return m_impl->isError();
}

bool Context::isSupported(SpecialFeatures _feature) const
{
	// TODO
	return true;
}