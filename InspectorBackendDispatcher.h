// Copyright (c) 2010 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
#ifndef InspectorBackendDispatcher_h
#define InspectorBackendDispatcher_h

#include <InspectorController.h>
#include <wtf/Forward.h>
#include <wtf/PassRefPtr.h>

namespace WebCore {

class InspectorApplicationCacheAgent;
class InspectorArray;
class InspectorBackend;
class InspectorClient;
class InspectorDOMAgent;
class InspectorDebuggerAgent;
class InspectorObject;
class InspectorProfilerAgent;
class InspectorValue;

class InspectorBackendDispatcher {
public:
    InspectorBackendDispatcher(InspectorController* inspectorController) : m_inspectorController(inspectorController) { }
    void reportProtocolError(const long callId, const String& method, const String& errorText) const;
    void dispatch(const String& message);
    static bool getCommandName(const String& message, String* result);

    static const char* populateScriptObjectsCmd;
    static const char* getSettingsCmd;
    static const char* storeLastActivePanelCmd;
    static const char* saveApplicationSettingsCmd;
    static const char* saveSessionSettingsCmd;
    static const char* enableSearchingForNodeCmd;
    static const char* disableSearchingForNodeCmd;
    static const char* enableMonitoringXHRCmd;
    static const char* disableMonitoringXHRCmd;
    static const char* enableResourceTrackingCmd;
    static const char* disableResourceTrackingCmd;
    static const char* getResourceContentCmd;
    static const char* reloadPageCmd;
    static const char* startTimelineProfilerCmd;
    static const char* stopTimelineProfilerCmd;
    static const char* enableDebuggerCmd;
    static const char* disableDebuggerCmd;
    static const char* setBreakpointCmd;
    static const char* removeBreakpointCmd;
    static const char* activateBreakpointsCmd;
    static const char* deactivateBreakpointsCmd;
    static const char* pauseCmd;
    static const char* resumeCmd;
    static const char* stepOverStatementCmd;
    static const char* stepIntoStatementCmd;
    static const char* stepOutOfFunctionCmd;
    static const char* setPauseOnExceptionsStateCmd;
    static const char* editScriptSourceCmd;
    static const char* getScriptSourceCmd;
    static const char* enableProfilerCmd;
    static const char* disableProfilerCmd;
    static const char* startProfilingCmd;
    static const char* stopProfilingCmd;
    static const char* getProfileHeadersCmd;
    static const char* getProfileCmd;
    static const char* removeProfileCmd;
    static const char* clearProfilesCmd;
    static const char* takeHeapSnapshotCmd;
    static const char* setInjectedScriptSourceCmd;
    static const char* dispatchOnInjectedScriptCmd;
    static const char* addScriptToEvaluateOnLoadCmd;
    static const char* removeAllScriptsToEvaluateOnLoadCmd;
    static const char* getChildNodesCmd;
    static const char* setAttributeCmd;
    static const char* removeAttributeCmd;
    static const char* setTextNodeValueCmd;
    static const char* getEventListenersForNodeCmd;
    static const char* copyNodeCmd;
    static const char* removeNodeCmd;
    static const char* changeTagNameCmd;
    static const char* getOuterHTMLCmd;
    static const char* setOuterHTMLCmd;
    static const char* addInspectedNodeCmd;
    static const char* performSearchCmd;
    static const char* searchCanceledCmd;
    static const char* pushNodeByPathToFrontendCmd;
    static const char* setDOMBreakpointCmd;
    static const char* removeDOMBreakpointCmd;
    static const char* clearConsoleMessagesCmd;
    static const char* highlightDOMNodeCmd;
    static const char* hideDOMNodeHighlightCmd;
    static const char* openInInspectedWindowCmd;
    static const char* getStylesCmd;
    static const char* getAllStylesCmd;
    static const char* getInlineStyleCmd;
    static const char* getComputedStyleCmd;
    static const char* getStyleSheetCmd;
    static const char* getRuleRangesCmd;
    static const char* applyStyleTextCmd;
    static const char* setStyleTextCmd;
    static const char* setStylePropertyCmd;
    static const char* toggleStyleEnabledCmd;
    static const char* setRuleSelectorCmd;
    static const char* addRuleCmd;
    static const char* getSupportedCSSPropertiesCmd;
    static const char* getCookiesCmd;
    static const char* deleteCookieCmd;
    static const char* getApplicationCachesCmd;
    static const char* releaseWrapperObjectGroupCmd;
    static const char* didEvaluateForTestInFrontendCmd;
    static const char* getDatabaseTableNamesCmd;
    static const char* executeSQLCmd;
    static const char* getDOMStorageEntriesCmd;
    static const char* setDOMStorageItemCmd;
    static const char* removeDOMStorageItemCmd;

private:
    void setBreakpoint(long callId, InspectorObject* requestMessageObject);
    void enableProfiler(long callId, InspectorObject* requestMessageObject);
    void getStyles(long callId, InspectorObject* requestMessageObject);
    void takeHeapSnapshot(long callId, InspectorObject* requestMessageObject);
    void stopProfiling(long callId, InspectorObject* requestMessageObject);
    void saveSessionSettings(long callId, InspectorObject* requestMessageObject);
    void executeSQL(long callId, InspectorObject* requestMessageObject);
    void enableResourceTracking(long callId, InspectorObject* requestMessageObject);
    void getStyleSheet(long callId, InspectorObject* requestMessageObject);
    void setStyleProperty(long callId, InspectorObject* requestMessageObject);
    void getCookies(long callId, InspectorObject* requestMessageObject);
    void releaseWrapperObjectGroup(long callId, InspectorObject* requestMessageObject);
    void searchCanceled(long callId, InspectorObject* requestMessageObject);
    void removeAllScriptsToEvaluateOnLoad(long callId, InspectorObject* requestMessageObject);
    void toggleStyleEnabled(long callId, InspectorObject* requestMessageObject);
    void setStyleText(long callId, InspectorObject* requestMessageObject);
    void disableResourceTracking(long callId, InspectorObject* requestMessageObject);
    void addInspectedNode(long callId, InspectorObject* requestMessageObject);
    void setOuterHTML(long callId, InspectorObject* requestMessageObject);
    void copyNode(long callId, InspectorObject* requestMessageObject);
    void clearProfiles(long callId, InspectorObject* requestMessageObject);
    void removeProfile(long callId, InspectorObject* requestMessageObject);
    void pushNodeByPathToFrontend(long callId, InspectorObject* requestMessageObject);
    void populateScriptObjects(long callId, InspectorObject* requestMessageObject);
    void setTextNodeValue(long callId, InspectorObject* requestMessageObject);
    void disableSearchingForNode(long callId, InspectorObject* requestMessageObject);
    void stepIntoStatement(long callId, InspectorObject* requestMessageObject);
    void disableProfiler(long callId, InspectorObject* requestMessageObject);
    void getApplicationCaches(long callId, InspectorObject* requestMessageObject);
    void activateBreakpoints(long callId, InspectorObject* requestMessageObject);
    void getAllStyles(long callId, InspectorObject* requestMessageObject);
    void resume(long callId, InspectorObject* requestMessageObject);
    void getComputedStyle(long callId, InspectorObject* requestMessageObject);
    void storeLastActivePanel(long callId, InspectorObject* requestMessageObject);
    void getRuleRanges(long callId, InspectorObject* requestMessageObject);
    void getScriptSource(long callId, InspectorObject* requestMessageObject);
    void openInInspectedWindow(long callId, InspectorObject* requestMessageObject);
    void setDOMBreakpoint(long callId, InspectorObject* requestMessageObject);
    void removeDOMStorageItem(long callId, InspectorObject* requestMessageObject);
    void editScriptSource(long callId, InspectorObject* requestMessageObject);
    void reloadPage(long callId, InspectorObject* requestMessageObject);
    void getOuterHTML(long callId, InspectorObject* requestMessageObject);
    void stopTimelineProfiler(long callId, InspectorObject* requestMessageObject);
    void setDOMStorageItem(long callId, InspectorObject* requestMessageObject);
    void getSupportedCSSProperties(long callId, InspectorObject* requestMessageObject);
    void stepOutOfFunction(long callId, InspectorObject* requestMessageObject);
    void performSearch(long callId, InspectorObject* requestMessageObject);
    void enableSearchingForNode(long callId, InspectorObject* requestMessageObject);
    void setPauseOnExceptionsState(long callId, InspectorObject* requestMessageObject);
    void changeTagName(long callId, InspectorObject* requestMessageObject);
    void removeAttribute(long callId, InspectorObject* requestMessageObject);
    void getProfile(long callId, InspectorObject* requestMessageObject);
    void saveApplicationSettings(long callId, InspectorObject* requestMessageObject);
    void getChildNodes(long callId, InspectorObject* requestMessageObject);
    void getDOMStorageEntries(long callId, InspectorObject* requestMessageObject);
    void getInlineStyle(long callId, InspectorObject* requestMessageObject);
    void removeBreakpoint(long callId, InspectorObject* requestMessageObject);
    void disableDebugger(long callId, InspectorObject* requestMessageObject);
    void stepOverStatement(long callId, InspectorObject* requestMessageObject);
    void pause(long callId, InspectorObject* requestMessageObject);
    void setInjectedScriptSource(long callId, InspectorObject* requestMessageObject);
    void getEventListenersForNode(long callId, InspectorObject* requestMessageObject);
    void removeDOMBreakpoint(long callId, InspectorObject* requestMessageObject);
    void getResourceContent(long callId, InspectorObject* requestMessageObject);
    void startTimelineProfiler(long callId, InspectorObject* requestMessageObject);
    void enableDebugger(long callId, InspectorObject* requestMessageObject);
    void addScriptToEvaluateOnLoad(long callId, InspectorObject* requestMessageObject);
    void setRuleSelector(long callId, InspectorObject* requestMessageObject);
    void setAttribute(long callId, InspectorObject* requestMessageObject);
    void disableMonitoringXHR(long callId, InspectorObject* requestMessageObject);
    void didEvaluateForTestInFrontend(long callId, InspectorObject* requestMessageObject);
    void getDatabaseTableNames(long callId, InspectorObject* requestMessageObject);
    void getSettings(long callId, InspectorObject* requestMessageObject);
    void clearConsoleMessages(long callId, InspectorObject* requestMessageObject);
    void highlightDOMNode(long callId, InspectorObject* requestMessageObject);
    void getProfileHeaders(long callId, InspectorObject* requestMessageObject);
    void removeNode(long callId, InspectorObject* requestMessageObject);
    void startProfiling(long callId, InspectorObject* requestMessageObject);
    void applyStyleText(long callId, InspectorObject* requestMessageObject);
    void hideDOMNodeHighlight(long callId, InspectorObject* requestMessageObject);
    void deactivateBreakpoints(long callId, InspectorObject* requestMessageObject);
    void addRule(long callId, InspectorObject* requestMessageObject);
    void enableMonitoringXHR(long callId, InspectorObject* requestMessageObject);
    void deleteCookie(long callId, InspectorObject* requestMessageObject);
    void dispatchOnInjectedScript(long callId, InspectorObject* requestMessageObject);

private:
    InspectorController* m_inspectorController;
};

} // namespace WebCore
#endif // !defined(InspectorBackendDispatcher_h)

