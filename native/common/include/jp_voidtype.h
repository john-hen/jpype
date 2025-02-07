/*****************************************************************************
   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

		http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.

   See NOTICE file for details.
 *****************************************************************************/
#ifndef _JP_VOID_TYPE_H_
#define _JP_VOID_TYPE_H_

class JPVoidType : public JPPrimitiveType
{
public:

	JPVoidType();
	~JPVoidType() override;

	JPClass* getBoxedClass(JPContext *context) const override
	{
		return context->_java_lang_Void;
	}

	JPMatch::Type findJavaConversion(JPMatch &match) override;
	JPPyObject  convertToPythonObject(JPJavaFrame& frame, jvalue val, bool cast) override;

	JPPyObject  invokeStatic(JPJavaFrame& frame, jclass, jmethodID, jvalue*) override;
	JPPyObject  invoke(JPJavaFrame& frame, jobject, jclass, jmethodID, jvalue*) override;

	JPPyObject  getStaticField(JPJavaFrame& frame, jclass c, jfieldID fid) override;
	void        setStaticField(JPJavaFrame& frame, jclass c, jfieldID fid, PyObject* val) override;
	JPPyObject  getField(JPJavaFrame& frame, jobject c, jfieldID fid) override;
	void        setField(JPJavaFrame& frame, jobject c, jfieldID fid, PyObject* val) override;

	jarray      newArrayOf(JPJavaFrame& frame, jsize size) override;
	void        setArrayRange(JPJavaFrame& frame, jarray,
			jsize start, jsize length, jsize step,
			PyObject *sequence) override;
	JPPyObject  getArrayItem(JPJavaFrame& frame, jarray, jsize ndx) override;
	void        setArrayItem(JPJavaFrame& frame, jarray, jsize ndx, PyObject* val) override;
	JPValue     getValueFromObject(const JPValue& obj) override;

	char getTypeCode() override;
	jlong getAsLong(jvalue v) override;
	jdouble getAsDouble(jvalue v) override;

	void getView(JPArrayView& view) override;
	void releaseView(JPArrayView& view) override;
	const char* getBufferFormat() override;
	Py_ssize_t getItemSize() override;
	void copyElements(JPJavaFrame &frame,
			jarray a, jsize start, jsize len,
			void* memory, int offset) override;
	PyObject *newMultiArray(JPJavaFrame &frame,
			JPPyBuffer& view, int subs, int base, jobject dims) override;
} ;

#endif // _JP_VOID_TYPE_H_
