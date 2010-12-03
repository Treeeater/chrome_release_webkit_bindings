// Copyright (c) 2010 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
#ifndef InspectorFrontend_h
#define InspectorFrontend_h

#include <wtf/Forward.h>
#include <wtf/PassRefPtr.h>

namespace WebCore {

class InspectorArray;
class InspectorClient;
class InspectorObject;
class InspectorValue;

class InspectorFrontend {
public:
    InspectorFrontend(InspectorClient* inspectorClient) : m_inspectorClient(inspectorClient) { }


    void updateResource(PassRefPtr<InspectorValue> resource);
    void sqlTransactionSucceeded(long transactionId, PassRefPtr<InspectorValue> columnNames, PassRefPtr<InspectorValue> values);
    void updateDOMStorage(int storageId);
    void searchingForNodeWasDisabled();
    void monitoringXHRWasEnabled();
    void attachDebuggerWhenShown();
    void didCommitLoad();
    void updatePauseOnExceptionsState(long state);
    void monitoringXHRWasDisabled();
    void parsedScriptSource(const String& sourceID, const String& url, const String& data, int firstLine, int scriptWorldType);
    void profilerWasEnabled();
    void timelineProfilerWasStopped();
    void addRecordToTimeline(PassRefPtr<InspectorObject> record);
    void childNodeRemoved(long parentId, long id);
    void profilerWasDisabled();
    void sqlTransactionFailed(long transactionId, PassRefPtr<InspectorValue> sqlError);
    void setDetachedRoot(PassRefPtr<InspectorObject> root);
    void showPanel(const String& panel);
    void searchingForNodeWasEnabled();
    void addDOMStorage(PassRefPtr<InspectorObject> storage);
    void evaluateForTestInFrontend(long testCallId, const String& script);
    void resumedScript();
    void resetProfilesPanel();
    void didCreateWorker(long id, const String& url, bool isShared);
    void selectDOMStorage(int storageId);
    void reset();
    void disconnectFromBackend();
    void timelineProfilerWasStarted();
    void updateNetworkState(bool isNowOnline);
    void pausedScript(PassRefPtr<InspectorValue> callFrames);
    void debuggerWasDisabled();
    void debuggerWasEnabled();
    void setRecordingProfile(bool isProfiling);
    void attributesUpdated(long id, PassRefPtr<InspectorArray> attributes);
    void selectDatabase(int databaseId);
    void failedToParseScriptSource(const String& url, const String& data, int firstLine, int errorLine, const String& errorMessage);
    void resourceTrackingWasDisabled();
    void updateConsoleMessageExpiredCount(unsigned long count);
    void restoredBreakpoint(const String& sourceID, const String& url, int line, bool enabled, const String& condition);
    void setChildNodes(long parentId, PassRefPtr<InspectorArray> nodes);
    void updateApplicationCacheStatus(int status);
    void addNodesToSearchResult(PassRefPtr<InspectorArray> nodeIds);
    void setDocument(PassRefPtr<InspectorValue> root);
    void consoleMessagesCleared();
    void addConsoleMessage(PassRefPtr<InspectorObject> messageObj);
    void resourceTrackingWasEnabled();
    void bringToFront();
    void updateFocusedNode(long nodeId);
    void updateConsoleMessageRepeatCount(unsigned long count);
    void addProfileHeader(PassRefPtr<InspectorObject> header);
    void removeResource(unsigned long identifier);
    void childNodeCountUpdated(long id, int newValue);
    void childNodeInserted(long parentId, long prevId, PassRefPtr<InspectorObject> node);
    void addDatabase(PassRefPtr<InspectorObject> database);
    void didDestroyWorker(long id);
    void inspectedURLChanged(const String& url);

private:
    InspectorClient* m_inspectorClient;
};

} // namespace WebCore
#endif // !defined(InspectorFrontend_h)

